#include <bits/stdc++.h>
#include <semaphore.h>
#include "../../utils/chrono.h"
using namespace std;

constexpr int READER_THREAD_NUM = 5;
constexpr int WRITER_THREAD_NUM = 5;
constexpr int READER_CNT = 200;
constexpr int WRITER_CNT = 200;
/*
1. 多个 Reader 可以同时读。
2. Writer 写的时候，不能有任何 Reader 或 Writer。
3. 如果 Reader 源源不断地来，Writer 可以一直等（Writer 可能饥饿）。
*/

int g_data{};

class sem_mutex {
public:
    sem_mutex() { sem_init(&_sem, 0, 1); }

    void lock() { sem_wait(&_sem); }

    void unlock() { sem_post(&_sem); }

private:
    sem_t _sem;
};

class sem_cv {
public:
    sem_cv() { sem_init(&_sem, 0, 0); }

    void wait() { sem_wait(&_sem); }

    void notify() { sem_post(&_sem); }

private:
    sem_t _sem;
};

namespace reader_first {
condition_variable cv;
mutex mu;
mutex mu_cout;

bool is_writing{false};
int cur_reader_cnt{};

void reader(int tid) {
    for (int i{}; i < READER_CNT; ++i) {
        { // 进入
            unique_lock lk(mu);
            cv.wait(lk, [] { return !is_writing; });
            ++cur_reader_cnt;
        }
        // 读取
        {
            lock_guard lk(mu_cout);
            cout << "reader thread " << tid
                 << " cur_reader_cnt: " << cur_reader_cnt << " data: " << g_data
                 << endl;
        }
        usleep(250);
        { // 离开
            unique_lock lk(mu);
            --cur_reader_cnt;
            if (cur_reader_cnt == 0) {
                cv.notify_all();
            }
        }
    }
}

void writer(int tid) {
    for (int i{}; i < WRITER_CNT; ++i) {
        { // 进入
            unique_lock lk(mu);
            cv.wait(lk, [] { return cur_reader_cnt == 0 && !is_writing; });
            is_writing = true;
        }
        {
            lock_guard lk(mu_cout);
            ++g_data;
            cout << "writer thread " << tid << " data: " << g_data << endl;
        }
        usleep(100);
        {
            unique_lock lk(mu);
            is_writing = false;
            cv.notify_all();
        }
    }
}

} // namespace reader_first

namespace writer_first {
condition_variable cv;
mutex mu;
mutex mu_cout;

bool is_writing{false};
int cur_reader_cnt{};
int waiting_writer_cnt{};

void reader(int tid) {
    for (int i{}; i < READER_CNT; ++i) {
        { // 进入
            unique_lock lk(mu);
            cv.wait(lk, [] { return !is_writing && 0 == waiting_writer_cnt; });
            ++cur_reader_cnt;
        }
        // 读取
        {
            lock_guard lk(mu_cout);
            cout << "reader thread " << tid
                 << " cur_reader_cnt: " << cur_reader_cnt << " data: " << g_data
                 << endl;
        }
        usleep(250);
        { // 离开
            unique_lock lk(mu);
            --cur_reader_cnt;
            if (cur_reader_cnt == 0) {
                cv.notify_all();
            }
        }
    }
}

void writer(int tid) {
    for (int i{}; i < WRITER_CNT; ++i) {
        { // 进入
            unique_lock lk(mu);
            ++waiting_writer_cnt;
            cv.wait(lk, [] { return cur_reader_cnt == 0 && !is_writing; });
            --waiting_writer_cnt;
            is_writing = true;
        }
        {
            lock_guard lk(mu_cout);
            ++g_data;
            cout << "writer thread " << tid << " data: " << g_data << endl;
        }
        usleep(100);
        {
            unique_lock lk(mu);
            is_writing = false;
            cv.notify_all();
        }
    }
}

} // namespace writer_first

namespace reader_writer_fair {
using mutex = ::sem_mutex; // 控制是否使用基于信号量的互斥锁实现
mutex mu_rw;
mutex mu_r;
mutex mu_cout; // 仅用来控制cout 打印正常
mutex mu_w;
/*
- mu_w  → 谁可以加入 reader group, 保护 reader group 的建立过程,
          writer来了之后禁止 reader 进入
- mu_r  → 谁可以修改 reader count 防的是进入段和离开段之间的竞争
- mu_rw → reader group 和 writer 谁能访问资源

                  mu_w
                   │
             ┌─────┴─────┐
             │           │
          reader       writer
             │           │
             ▼           ▼
       建立/加入       获取资源
       reader group    mu_rw
*/
int cur_reader_cnt{};

void reader(int tid) {
    for (int i{}; i < READER_CNT; ++i) {
        int cnt_snapshot{};
        // 仅在临界区内取全局变量的快照, 不会被 tsan 检出 data-race
        {
            lock_guard lk_w(mu_w);
            lock_guard lk(mu_r);
            if (cur_reader_cnt == 0) {
                mu_rw.lock(); // 首个读进程负责加锁
            }
            cnt_snapshot = ++cur_reader_cnt;
        }
        {
            lock_guard lk(mu_cout); // 多个读者打印会乱
            cout << "reader thread " << tid
                 << " cur_reader_cnt: " << cnt_snapshot << " data: " << g_data
                 << endl;
        }
        {
            lock_guard lk(mu_r);
            --cur_reader_cnt;
            if (cur_reader_cnt == 0) {
                mu_rw.unlock(); // 最后一个读进程负责解锁
            }
        }
        usleep(100); // 让出 CPU
    }
}

void writer(int tid) {
    for (int i{}; i < WRITER_CNT; ++i) {
        {
            lock_guard lk_w(mu_w);
            lock_guard lk(mu_rw);
            ++g_data;
            cout << "writer thread " << tid << " data: " << g_data << endl;
        }
        usleep(100);
    }
}

} // namespace reader_writer_fair

namespace reader_writer_fair_batch {
using mutex = ::sem_mutex; // 控制是否使用基于信号量的互斥锁实现

mutex mu_rw;
mutex mu_r;
mutex mu_cout; // 仅用来控制cout 打印正常
mutex mu_w;
/*
这个版本和上一个的区别在于是否让读者组 batch.
上一版如果 R1,W1,R2,R3 这样的顺序到来, R1正在执行, 此时 W1 拿到了 mu_w, 那么
R2R3 会等 mu_w, 直到 W1 执行完释放掉 mu_w 后才能继续执行.

本版允许后到的读者"搭车"已经存在的读者组(不走 mu_w 闸门), 于是上例中 R2R3 可以
直接加入 R1 所在的组, 不必等 W1. 但每个读者组最多只能被搭 MAX_BATCH_JOIN 次,
配额用完后读者必须回到 mu_w 排队, 这样读者组一定能排空, 写者的等待仍然有上界.
MAX_BATCH_JOIN == 0 时行为退化成上一版.

注意: 搭车的前提是 cur_reader_cnt > 0 时读者组一定持有 mu_rw, 因此
cur_reader_cnt 在进入/离开两侧都必须由 mu_r 保护, 进入时是 mu_w -> mu_r
的嵌套(上一版进入只用了 mu_w, 与离开侧的 mu_r 存在竞争, 可能出现读者组丢掉 mu_rw
的情况).
*/
constexpr int MAX_BATCH_JOIN = // 0;
    READER_THREAD_NUM - 1;     // 每个读者组最多允许搭车的读者数

int cur_reader_cnt{};
int batch_join_cnt{}; // 当前读者组已被搭车的次数, 由 mu_r 保护

void reader(int tid) {
    for (int i{}; i < READER_CNT; ++i) {
        bool joined{false};
        int cnt_snapshot{};
        // 仅在临界区内取全局变量的快照, 不会被 tsan 检出 data-race

        { // 先尝试搭车当前读者组
            lock_guard lk(mu_r);
            if (cur_reader_cnt > 0 && batch_join_cnt < MAX_BATCH_JOIN) {
                ++batch_join_cnt;
                cnt_snapshot = ++cur_reader_cnt;
                joined = true;
            }
        }
        if (!joined) { // 组已排空或搭车配额用完, 过 mu_w 闸门排队
            lock_guard lk_w(mu_w);
            lock_guard lk_r(mu_r);
            if (cur_reader_cnt == 0) {
                mu_rw.lock();       // 首个读进程负责加锁
                batch_join_cnt = 0; // 新的读者组, 重置搭车配额
            }
            cnt_snapshot = ++cur_reader_cnt;
        }
        {
            lock_guard lk(mu_cout); // 多个读者打印会乱
            cout << "reader thread " << tid
                 << (joined ? " [batch]" : " [queue]")
                 << " cur_reader_cnt: " << cnt_snapshot << " data: " << g_data
                 << endl;
        }
        {
            lock_guard lk(mu_r);
            --cur_reader_cnt;
            if (cur_reader_cnt == 0) {
                mu_rw.unlock(); // 最后一个读进程负责解锁
            }
        }
        usleep(100); // 让出 CPU
    }
}

void writer(int tid) {
    for (int i{}; i < WRITER_CNT; ++i) {
        {
            lock_guard lk_w(mu_w);
            lock_guard lk(mu_rw);
            ++g_data;
            cout << "writer thread " << tid << " data: " << g_data << endl;
        }
        usleep(100);
    }
}

} // namespace reader_writer_fair_batch

void test() {
    // using namespace reader_first;
    // using namespace writer_first;
    using namespace reader_writer_fair;
    // using namespace reader_writer_fair_batch;

    vector<thread> vt_reader;
    vt_reader.reserve(READER_THREAD_NUM);
    vector<thread> vt_writer;
    vt_writer.reserve(WRITER_THREAD_NUM);

    for (int i{}; i < READER_THREAD_NUM; ++i) {
        vt_reader.emplace_back(reader, i);
    }
    for (int i{}; i < WRITER_THREAD_NUM; ++i) {
        vt_writer.emplace_back(writer, i);
    }

    for (int i{}; i < READER_THREAD_NUM; ++i) {
        vt_reader[i].join();
    }
    for (int i{}; i < WRITER_THREAD_NUM; ++i) {
        vt_writer[i].join();
    }
}

int main() {
    TimeCost tc;
    test();
    cout << "\ntime cost:" << tc.get_time_cost() << "ms\n";
    return 0;
}