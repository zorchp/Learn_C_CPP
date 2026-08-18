#include <bits/stdc++.h>
#include "../../utils/chrono.h"
using namespace std;
constexpr int N = 100; // 单个生产者线程生产的总数
constexpr int C = 5;   // 共享容器的大小
constexpr int PRODUCER_THREAD_NUM = 1;
constexpr int CONSUMER_THREAD_NUM = 2;
constexpr int ONE_CONSUMER_N = N * PRODUCER_THREAD_NUM / CONSUMER_THREAD_NUM;

queue<int> q;

namespace busy_wait {
mutex mu_q;

void producer(int tid) {
    for (int i{}; i < N; ++i) {
        while (true) {
            {
                lock_guard _(mu_q);
                if (q.size() != C) {
                    q.push(i);
                    cout << "producer thread" << tid << " : " << i
                         << " pushed, size:" << q.size() << endl;
                    break;
                }
            }
            usleep(1000); // sleep 需要在锁的作用域之外, 否则其他线程没法拿到锁
        }
    }
}

void consumer(int tid) {
    for (int i{}; i < ONE_CONSUMER_N; ++i) {

        while (true) {
            {
                lock_guard _(mu_q);
                if (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    cout << "consumer thread" << tid << " : " << x
                         << " poped, size:" << q.size() << endl;
                    break;
                }
            }
            usleep(2000);
        }
    }
}
} // namespace busy_wait

namespace notify_1lock {
condition_variable cv_is_full;
condition_variable cv_is_empty;
mutex mu_q;

void producer(int tid) {
    for (int i{}; i < N; ++i) {
        unique_lock lk(mu_q);
        cv_is_full.wait(lk, [] { return q.size() != C; });

        q.push(i);
        cout << "producer thread" << tid << " : " << i
             << " pushed, size:" << q.size() << endl;
        cv_is_empty.notify_all();
        usleep(1000);
    }
}

void consumer(int tid) {
    for (int i{}; i < ONE_CONSUMER_N; ++i) {
        unique_lock lk(mu_q);
        cv_is_empty.wait(lk, [] { return !q.empty(); });
        assert(!q.empty());
        int x = q.front();
        q.pop();
        cout << "consumer thread" << tid << " : " << x
             << " poped, size:" << q.size() << endl;
        cv_is_full.notify_all();
        usleep(2000);
    }
}

} // namespace notify_1lock


void test() {
    // using namespace busy_wait;
    using namespace notify_1lock;

    vector<thread> vt_producer;
    vt_producer.reserve(PRODUCER_THREAD_NUM);
    vector<thread> vt_consumer;
    vt_consumer.reserve(CONSUMER_THREAD_NUM);
    for (int i{}; i < PRODUCER_THREAD_NUM; ++i) {
        vt_producer.emplace_back(producer, i);
    }
    for (int i{}; i < CONSUMER_THREAD_NUM; ++i) {
        vt_consumer.emplace_back(consumer, i);
    }

    for (int i{}; i < PRODUCER_THREAD_NUM; ++i) {
        vt_producer[i].join();
    }
    for (int i{}; i < CONSUMER_THREAD_NUM; ++i) {
        vt_consumer[i].join();
    }
}

int main() {
    TimeCost tc;
    test();
    cout << "\ntime cost:" << tc.get_time_cost() << "ms\n";
    return 0;
}