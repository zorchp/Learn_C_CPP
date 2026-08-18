#include <bits/stdc++.h>
#include "../../utils/chrono.h"
using namespace std;
constexpr int N = 100;

template <typename... Threads>
void join_all(Threads&... threads) {
    (threads.join(), ...);
}

namespace basic {
void print_a() {
    for (int i{}; i < N; ++i) {
        cout << 'A' << flush;
    }
}

void print_b() {
    for (int i{}; i < N; ++i) {
        cout << 'B' << flush;
    }
}
} // namespace basic

namespace busy_wait {
atomic_bool is_a_printed{false}; // ok

// bool is_a_printed{false}; // oops!

void print_a() {
    for (int i{}; i < N; ++i) {
        while (is_a_printed.load(memory_order_acquire));
        cout << 'A' << flush;
        is_a_printed.store(true, memory_order_release);
    }
}

void print_b() {
    for (int i{}; i < N; ++i) {
        while (!is_a_printed.load(memory_order_acquire));
        cout << 'B' << flush;
        is_a_printed.store(false, memory_order::release);
    }
}
} // namespace busy_wait

namespace notify {
condition_variable cv;
mutex mx;

bool is_a_printed{false};

void print_a() {
    unique_lock lock(mx);
    for (int i{}; i < N; ++i) {
        // unique_lock lock(mx);
        cv.wait(lock, [] { return !is_a_printed; });
        cout << 'A' << flush;
        is_a_printed = true;
        cv.notify_one();
    }
}

void print_b() {
    unique_lock lock(mx);
    for (int i{}; i < N; ++i) {
        // unique_lock lock(mx);
        cv.wait(lock, [] { return is_a_printed; });
        cout << 'B' << flush;
        is_a_printed = false;
        cv.notify_one();
    }
}
} // namespace notify

void test() {
    // using namespace basic;
    // using namespace busy_wait;
    using namespace notify;
    // thread t1(print_a), t2(print_b);
    thread t2(print_a), t1(print_b);
    // join_all(t2, t1);
    join_all(t1, t2);
}

int main() {
    TimeCost tc;
    test();
    cout << "\ntime cost:" << tc.get_time_cost() << "s\n";
    return 0;
}