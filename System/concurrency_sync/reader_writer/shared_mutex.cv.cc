#include <bits/stdc++.h>
#include "../../utils/chrono.h"
using namespace std;

void bit_basic() {
    // unsigned _M_state;
    static constexpr unsigned _S_write_entered =
        1U << (sizeof(unsigned) * __CHAR_BIT__ - 1);
    static constexpr unsigned _S_max_readers = ~_S_write_entered;
    cout << __CHAR_BIT__ << endl;                    // 8
    cout << sizeof(unsigned) << endl;                // 4
    cout << sizeof(unsigned) * __CHAR_BIT__ << endl; // 32
    cout << _S_write_entered << endl; // 2^31 abs(INT_MIN), 0x80000000
    cout << _S_max_readers << endl;   // 2^31 - 1 (INT_MAX), 0x7fffffff
    assert(abs(INT_MIN) == _S_write_entered);
    assert(INT_MAX == _S_max_readers);
    unsigned x = (_S_max_readers << 1) + 1;  // 0xffffffff
    unsigned x1 = (_S_max_readers << 1) + 2; // 0
    cout << x << endl;
    cout << x1 << endl;
}

constexpr int READER_THREAD_NUM = 5;
constexpr int WRITER_THREAD_NUM = 5;
constexpr int READER_CNT = 200;
constexpr int WRITER_CNT = 200;

namespace std_shared_mutex {
class __shared_mutex_cv {
    friend class shared_timed_mutex;

    // Based on Howard Hinnant's reference implementation from N2406.

    // The high bit of _M_state is the write-entered flag which is set to
    // indicate a writer has taken the lock or is queuing to take the lock.
    // The remaining bits are the count of reader locks.
    //
    // To take a reader lock, block on gate1 while the write-entered flag is
    // set or the maximum number of reader locks is held, then increment the
    // reader lock count.
    // To release, decrement the count, then if the write-entered flag is set
    // and the count is zero then signal gate2 to wake a queued writer,
    // otherwise if the maximum number of reader locks was held signal gate1
    // to wake a reader.
    //
    // To take a writer lock, block on gate1 while the write-entered flag is
    // set, then set the write-entered flag to start queueing, then block on
    // gate2 while the number of reader locks is non-zero.
    // To release, unset the write-entered flag and signal gate1 to wake all
    // blocked readers and writers.
    //
    // This means that when no reader locks are held readers and writers get
    // equal priority. When one or more reader locks is held a writer gets
    // priority and no more reader locks can be taken while the writer is
    // queued.

    // Only locked when accessing _M_state or waiting on condition variables.
    mutex _M_mut;
    // Used to block while write-entered is set or reader count at maximum.
    condition_variable _M_gate1;
    // Used to block queued writers while reader count is non-zero.
    condition_variable _M_gate2;
    // The write-entered flag and reader count.
    unsigned _M_state;

    static constexpr unsigned _S_write_entered =
        1U << (sizeof(unsigned) * __CHAR_BIT__ - 1);
    static constexpr unsigned _S_max_readers = ~_S_write_entered;

    // Test whether the write-entered flag is set. _M_mut must be locked.
    bool _M_write_entered() const { return _M_state & _S_write_entered; }

    // The number of reader locks currently held. _M_mut must be locked.
    unsigned _M_readers() const { return _M_state & _S_max_readers; }

public:
    __shared_mutex_cv() : _M_state(0) {}

    ~__shared_mutex_cv() { __glibcxx_assert(_M_state == 0); }

    __shared_mutex_cv(const __shared_mutex_cv&) = delete;
    __shared_mutex_cv& operator=(const __shared_mutex_cv&) = delete;

    // Exclusive ownership

    void lock() {
        unique_lock<mutex> __lk(_M_mut);
        // Wait until we can set the write-entered flag.
        _M_gate1.wait(__lk, [this] { return !_M_write_entered(); });
        _M_state |= _S_write_entered;
        // Then wait until there are no more readers.
        _M_gate2.wait(__lk, [this] { return _M_readers() == 0; });
    }

    bool try_lock() {
        unique_lock<mutex> __lk(_M_mut, try_to_lock);
        if (__lk.owns_lock() && _M_state == 0) {
            _M_state = _S_write_entered;
            return true;
        }
        return false;
    }

    void unlock() {
        lock_guard<mutex> __lk(_M_mut);
        __glibcxx_assert(_M_write_entered());
        _M_state = 0;
        // call notify_all() while mutex is held so that another thread can't
        // lock and unlock the mutex then destroy *this before we make the call.
        _M_gate1.notify_all();
    }

    // Shared ownership

    void lock_shared() {
        unique_lock<mutex> __lk(_M_mut);
        _M_gate1.wait(__lk, [this] { return _M_state < _S_max_readers; });
        ++_M_state;
    }

    bool try_lock_shared() {
        unique_lock<mutex> __lk(_M_mut, try_to_lock);
        if (!__lk.owns_lock()) return false;
        if (_M_state < _S_max_readers) {
            ++_M_state;
            return true;
        }
        return false;
    }

    void unlock_shared() {
        lock_guard<mutex> __lk(_M_mut);
        __glibcxx_assert(_M_readers() > 0);
        auto __prev = _M_state--;
        if (_M_write_entered()) {
            // Wake the queued writer if there are no more readers.
            if (_M_readers() == 0) _M_gate2.notify_one();
            // No need to notify gate1 because we give priority to the queued
            // writer, and that writer will eventually notify gate1 after it
            // clears the write-entered flag.
        } else {
            // Wake any thread that was blocked on reader overflow.
            if (__prev == _S_max_readers) _M_gate1.notify_one();
        }
    }
};

__shared_mutex_cv rw_lock;
mutex mu_cout;
int g_data{};

void reader(int tid) {
    for (int _{}; _ < READER_CNT; ++_) {
        {
            std::shared_lock lk(rw_lock);
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
            unique_lock lk(rw_lock);
            ++g_data;
            cout << "writer thread " << tid << " data: " << g_data << endl;
        }
        this_thread::sleep_for(10ms);
    }
}
} // namespace std_shared_mutex

void test() {
    using namespace std_shared_mutex;
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

void shared_mutex_test() {
    TimeCost tc;
    test();
    cout << "\ntime cost:" << tc.get_time_cost() << "ms\n";
}

int main() {
    // bit_basic();
    shared_mutex_test();
    return 0;
}