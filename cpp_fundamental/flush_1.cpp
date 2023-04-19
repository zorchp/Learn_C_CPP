#include <iostream>
#include <chrono>
#include <unistd.h>
using namespace std;

template <typename Diff>
void log_progress(Diff d) {
    std::cout
        << "..("
        << std::chrono::duration_cast<std::chrono::milliseconds>(d).count()
        << " ms).." << std::unitbuf;
}
void t1() {
    volatile int sink = 0;

    auto t1 = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < 5; ++j) {
        for (int n = 0; n < 10000; ++n)
            for (int m = 0; m < 20000; ++m) sink += m * n; // do some work
        auto now = std::chrono::high_resolution_clock::now();
        log_progress(now - t1);
    }
    std::cout << '\n';
}

void t2() {
    for (int i{}; i < 1000000; ++i) {
        float tmp = i * 1.;
        sleep(1);
        cout << tmp << flush << "\r";
    }
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}