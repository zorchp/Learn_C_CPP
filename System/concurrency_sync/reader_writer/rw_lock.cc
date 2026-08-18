#include <bits/stdc++.h>
#include <semaphore.h>
#include "../../utils/chrono.h"
using namespace std;

constexpr int READER_THREAD_NUM = 5;
constexpr int WRITER_THREAD_NUM = 2;
constexpr int READER_CNT = 200;
constexpr int WRITER_CNT = 200;
/*
1. 多个 Reader 可以同时读。
2. Writer 写的时候，不能有任何 Reader 或 Writer。
3. 如果 Reader 源源不断地来，Writer 可以一直等（Writer 可能饥饿）。
*/

int g_data{};

#define DISABLE_COPY(class_name)            \
    class_name(const class_name&) = delete; \
    class_name& operator=(const class_name&) = delete

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

namespace reader_writer_fair {
using mutex = ::sem_mutex; // 控制是否使用基于信号量的互斥锁实现
mutex mu_cout;

class rw_lock_t {
public:
    void rlock();
    void runlock();
    void wlock();
    void wunlock();

    class r_lock_guard_t {
        rw_lock_t& _rw_lock;
        DISABLE_COPY(r_lock_guard_t);

    public:
        explicit r_lock_guard_t(rw_lock_t& rw_lock) : _rw_lock(rw_lock) {
            _rw_lock.rlock();
        }

        ~r_lock_guard_t() { _rw_lock.runlock(); }
    };

    class w_lock_guard_t {
        rw_lock_t& _rw_lock;
        DISABLE_COPY(w_lock_guard_t);


    public:
        explicit w_lock_guard_t(rw_lock_t& rw_lock) : _rw_lock(rw_lock) {
            _rw_lock.wlock();
        }

        ~w_lock_guard_t() { _rw_lock.wunlock(); }
    };

private:
    mutex mu_rw;
    mutex mu_r;
    mutex mu_w;
    int cur_reader_cnt{};
};

void rw_lock_t::rlock() {
    lock_guard lk_w(mu_w);
    lock_guard lk(mu_r);
    if (cur_reader_cnt == 0) {
        mu_rw.lock(); // 首个读进程负责加锁
    }
    ++cur_reader_cnt;
}

void rw_lock_t::runlock() {
    lock_guard lk(mu_r);
    --cur_reader_cnt;
    if (cur_reader_cnt == 0) {
        mu_rw.unlock(); // 最后一个读进程负责解锁
    }
}

void rw_lock_t::wlock() {
    mu_w.lock();
    mu_rw.lock();
}

void rw_lock_t::wunlock() {
    mu_w.unlock();
    mu_rw.unlock();
}

rw_lock_t rw_lock;

void reader(int tid) {
    for (int _{}; _ < READER_CNT; ++_) {
        {
            rw_lock_t::r_lock_guard_t _(rw_lock);
            {
                lock_guard lk(mu_cout); // 多个读者打印会乱
                cout << "reader thread " << tid << " data: " << g_data << endl;
            }
        }
        this_thread::sleep_for(10ms);
    }
}

void writer(int tid) {
    for (int _{}; _ < WRITER_CNT; ++_) {
        {
            rw_lock_t::w_lock_guard_t _(rw_lock);
            ++g_data;
            cout << "writer thread " << tid << " data: " << g_data << endl;
        }
        this_thread::sleep_for(10ms);
    }
}

} // namespace reader_writer_fair

void test() {
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



