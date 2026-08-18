#include <bits/stdc++.h>
#include "../../utils/chrono.h"
using namespace std;
constexpr int N = 100;

template <typename... Threads>
void join_all(Threads&... threads) {
    (threads.join(), ...);
}

namespace busy_wait3bool {
atomic_bool is_a_printed{false};
atomic_bool is_b_printed{false};
atomic_bool is_c_printed{true};

void print_a() {
    for (int i{}; i < N; ++i) {
        // 如果 a 打印了或者 c 没打印, 等
        while (is_a_printed.load(memory_order_acquire) ||
               !is_c_printed.load(std::memory_order_acquire));
        cout << 'A' << flush;
        is_a_printed.store(true, memory_order_release);
        is_b_printed.store(false, memory_order_release);
    }
}

void print_b() {
    for (int i{}; i < N; ++i) {
        while (!is_a_printed.load(memory_order_acquire) ||
               is_b_printed.load(std::memory_order::acquire));
        cout << 'B' << flush;
        is_b_printed.store(true, memory_order::release);
        is_c_printed.store(false, memory_order::release);
    }
}

void print_c() {
    for (int i{}; i < N; ++i) {
        while (is_c_printed.load(memory_order_acquire) ||
               !is_b_printed.load(std::memory_order::acquire));
        cout << 'C' << flush;
        is_c_printed.store(true, memory_order::release);
        is_a_printed.store(false, memory_order::release);
    }
}
} // namespace busy_wait3bool

namespace notify3bool {
condition_variable cv_notify_a, cv_notify_b, cv_notify_c;
mutex mx;

bool is_a_printed{false};
bool is_b_printed{false};
bool is_c_printed{true};

void print_a() {
    unique_lock lock(mx);
    for (int i{}; i < N; ++i) {
        // unique_lock lock(mx);
        cv_notify_a.wait(lock, [] { return !is_a_printed && is_c_printed; });
        cout << 'A' << flush;
        is_a_printed = true;
        is_b_printed = false;
        cv_notify_b.notify_one();
    }
}

void print_b() {
    unique_lock lock(mx);
    for (int i{}; i < N; ++i) {
        // unique_lock lock(mx);
        cv_notify_b.wait(lock, [] { return is_a_printed && !is_b_printed; });
        cout << 'B' << flush;
        is_b_printed = true;
        is_c_printed = false;
        cv_notify_c.notify_one();
    }
}

void print_c() {
    unique_lock lock(mx);
    for (int i{}; i < N; ++i) {
        // unique_lock lock(mx);
        cv_notify_c.wait(lock, [] { return is_b_printed && !is_c_printed; });
        cout << 'C' << flush;
        is_c_printed = true;
        is_a_printed = false;
        cv_notify_a.notify_one();
    }
}
} // namespace notify3bool

namespace notify1int {
condition_variable cv;
mutex mx;
int turn{}; // 0:a, 1:b, 2:c

void print_a() {
    unique_lock lock(mx);
    for (int i{}; i < N; ++i) {
        cv.wait(lock, [] { return turn == 0; });
        cout << 'A' << flush;
        turn = 1;
        cv.notify_all();
    }
}

void print_b() {
    unique_lock lock(mx);
    for (int i{}; i < N; ++i) {
        // unique_lock lock(mx);
        cv.wait(lock, [] { return turn == 1; });
        cout << 'B' << flush;
        turn = 2;
        cv.notify_all();
    }
}

void print_c() {
    unique_lock lock(mx);
    for (int i{}; i < N; ++i) {
        // unique_lock lock(mx);
        cv.wait(lock, [] { return turn == 2; });
        cout << 'C' << flush;
        turn = 0;
        cv.notify_all();
    }
}
} // namespace notify1int

namespace busy_wait1int {
atomic_int turn{};

void print_a() {
    for (int i{}; i < N; ++i) {
        // 如果 a 打印了或者 c 没打印, 等
        while (turn.load() != 0);
        cout << 'A' << flush;
        turn.store(1);
    }
}

void print_b() {
    for (int i{}; i < N; ++i) {
        while (turn.load() != 1);
        cout << 'B' << flush;
        turn.store(2);
    }
}

void print_c() {
    for (int i{}; i < N; ++i) {
        while (turn.load() != 2);
        cout << 'C' << flush;
        turn.store(0);
    }
}
} // namespace busy_wait1int

void test() {
    using namespace busy_wait3bool; // 1s
    // using namespace busy_wait1int; // 1s
    // using namespace notify3bool; // 2s
    // using namespace notify1int; //2.5s
    thread t2(print_a), t1(print_b), t3(print_c);
    join_all(t1, t2, t3);
}

int main() {
    TimeCost tc;
    test();
    cout << "\ntime cost:" << tc.get_time_cost() << "s\n";
    return 0;
}