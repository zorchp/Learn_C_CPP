#include <bits/stdc++.h>
#include "../../utils/chrono.h"
using namespace std;
constexpr int N = 100;
constexpr int THREAD_NUM = 5;

namespace notify {
condition_variable cv;
mutex mx;
int turn{};

void worker(int target) {
    unique_lock lock(mx);
    for (int i{}; i < N; ++i) {
        cv.wait(lock, [target] { return turn == target; });
        cout << char('A' + target) << flush;
        turn = (target + 1) % THREAD_NUM;
        cv.notify_all();
    }
}

} // namespace notify

namespace busy_wait {
atomic_int turn{}; // 状态转换

void worker(int target) {
    for (int i{}; i < N; ++i) {
        while (turn.load() != target);
        cout << char('A' + target) << flush;
        turn.store((target + 1) % THREAD_NUM);
    }
}

} // namespace busy_wait

namespace busy_wait_cxx20 {
atomic_int turn{}; // 状态转换

void worker(int target) {
    for (int i{}; i < N; ++i) {

        // while (turn.load(std::memory_order_acquire) != target) {
        //     turn.wait((target + THREAD_NUM - 1) % THREAD_NUM);
        // }
        while (true) {
            int cur = turn.load();
            if (cur == target) {
                break;
            }
            turn.wait(cur);
        }
        cout << char('A' + target) << flush;
        turn.store((target + 1) % THREAD_NUM);
        turn.notify_all();
    }
}

} // namespace busy_wait_cxx20

void test() {
    // using namespace busy_wait; //
    using namespace busy_wait_cxx20; //
    // using namespace notify; //
    vector<thread> vt;
    vt.reserve(THREAD_NUM);
    for (int i{}; i < THREAD_NUM; ++i) {
        vt.emplace_back(worker, i);
    }
    for (auto& t : vt) {
        t.join();
    }
}

int main() {
    TimeCost tc;
    test();
    cout << "\ntime cost:" << tc.get_time_cost() << "s\n";
    return 0;
}