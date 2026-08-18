#include <bits/stdc++.h>
#include "../../utils/chrono.h"
using namespace std;
constexpr int N = 10;
constexpr int C = 5;

template <typename... Threads>
void join_all(Threads&... threads) {
    (threads.join(), ...);
}

queue<int> q;

namespace busy_wait {
atomic_bool is_full{false};
atomic_bool is_empty{true};
mutex mu;

void producer() {
    for (int i{}; i < N; ++i) {
        while (is_full.load(memory_order_acquire));

        {
            lock_guard _(mu);
            q.push(i);
            cout << i << " pushed, size:" << q.size() << "\n" << flush;
            is_empty.store(false, memory_order_release);
            is_full.store(q.size() == N);
        }
        sleep(1);
    }
}

void consumer() {
    for (int i{}; i < N; ++i) {
        while (is_empty.load(memory_order_acquire));

        {
            lock_guard _(mu);
            assert(!q.empty());
            auto x = q.front();
            q.pop();
            cout << x << " poped, size:" << q.size() << "\n" << flush;
            is_full.store(false, memory_order::release);
            is_empty.store(q.empty());
        }
        sleep(2);
    }
}
} // namespace busy_wait

namespace busy_wait_lock {

mutex mu;

void producer() {
    for (int i{}; i < N; ++i) {
        while (true) {
            lock_guard _(mu);
            if (q.size() != N) {
                q.push(i);
                cout << i << " pushed, size:" << q.size() << "\n" << flush;
                break;
            }
        }
        sleep(1);
    }
}

void consumer() {
    for (int i{}; i < N; ++i) {
        while (true) {
            lock_guard _(mu);
            if (!q.empty()) {
                auto x = q.front();
                q.pop();
                cout << x << " poped, size:" << q.size() << "\n" << flush;
                break;
            }
        }
        sleep(1);
    }
}
} // namespace busy_wait_lock

namespace notify_1lock {
condition_variable cv_is_full;
condition_variable cv_is_empty;
mutex mu;

void producer() {
    unique_lock lk(mu);
    for (int i{}; i < N; ++i) {
        cv_is_full.wait(lk, [] { // 实际并没有陷入内核, 把当前线程加入等待队列
            cout << "xx" << to_string(q.size() != C) + "xx" << endl;
            return q.size() != C;
        });
        q.push(i);
        cout << i << " pushed, size:" << q.size() << "\n" << flush;
        cv_is_empty.notify_one();
        usleep(100);
    }
}

void consumer() {
    unique_lock lk(mu);
    for (int i{}; i < N; ++i) {
        cv_is_empty.wait(lk, [] { return !q.empty(); });
        auto x = q.front();
        q.pop();
        cout << x << " poped, size:" << q.size() << "\n" << flush;
        cv_is_full.notify_one();
        usleep(100);
    }
}
} // namespace notify_1lock

/*
STL 的  cv.wait(lock, cond), 类似于
while(true) {
    if (cond) {
        break;
    }
    cv.wait(lock); // 这里会实际释放锁, sleep, 然后再
}
即:
              线程A

              lock(mx)  这个是 unique_lock 构造函数执行的获取锁
                  │
                  ▼
         判断 predicate()
                  │
          ┌───────┴────────┐
          │                │
       true              false
          │                │
          ▼                ▼
       return        加入 cv 等待队列
                           │
                           ▼
              unlock(mx) + sleep
                 （原子完成）
                           │
                           │
───────────────────────────┼────────────────────────

                    线程B

              lock(mx)
                  │
                  ▼
         修改共享数据
      （例如 ready=true）
                  │
                  ▼
             unlock(mx)
                  │
                  ▼
           notify_one()
                  │
                  ▼
      从 cv 等待队列中唤醒A

───────────────────────────┼────────────────────────

                    线程A

                被唤醒
                  │
                  ▼
            lock(mx)
                  │
                  ▼
        再次判断 predicate()
                  │
          ┌───────┴────────┐
          │                │
       true              false
          │                │
          ▼                ▼
      wait 返回       再次 wait


如果一个线程可能连续很多次调用 wait(lock, pred)，而 pred 大概率一直为
true，那么不要把 unique_lock 放在大循环外面。 因为这样就意味着：

lock
    ↓
pred=true
    ↓
不释放锁(因为一开始 unique_lock 构造的时候就执行了 .lock())
    ↓
继续下一轮
    ↓
pred=true
    ↓
……
这样一直没有陷入内核态把当前线程加入等待队列, 也就没有在 pthread_cond_wait
中释放锁 另一个线程可能长期拿不到这把锁。

反过来，如果像 AB 交替打印那样，除了第一次之外几乎每轮 pred 都会变成
false，从而每轮都会真正执行一次 wait(lock)，那么把 unique_lock 放在 for
外就没有问题，因为锁会在 wait()
内部不断地释放、重新获取，两条线程能够自然地交替运行。
*/

namespace notify_1lock_scope {
condition_variable cv_is_full;
condition_variable cv_is_empty;
mutex mu_q;

void producer() {

    for (int i{}; i < N; ++i) {
        {
            unique_lock lk(mu_q);
            cv_is_full.wait(lk, [] {
                if (q.size() == C) {
                    cout << this_thread::get_id() << " wait in kernel\n";
                }
                return q.size() != C;
            });
            q.push(i);
            cout << i << " pushed, size:" << q.size() << "\n" << flush;
        }
        cv_is_empty.notify_one();
        usleep(3'000);
    }
}

void consumer() {

    for (int i{}; i < N; ++i) {
        {
            unique_lock lk(mu_q);
            cv_is_empty.wait(lk, [] { return !q.empty(); });
            auto x = q.front();
            q.pop();
            cout << x << " poped, size:" << q.size() << "\n" << flush;
        }
        cv_is_full.notify_one();
        usleep(50'000);
    }
}
} // namespace notify_1lock_scope

void test() {
    // using namespace busy_wait;
    // using namespace busy_wait_lock;
    // using namespace notify_1lock;
    using namespace notify_1lock_scope;
    thread t2(consumer), t1(producer);
    cout << "t1 id:" << t1.get_id() << endl;
    cout << "t2 id:" << t2.get_id() << endl;
    join_all(t1, t2);
}

int main() {
    TimeCost tc;
    test();
    cout << "\ntime cost:" << tc.get_time_cost() << "ms\n";
    return 0;
}