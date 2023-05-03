#include <iostream>
#include <chrono>
#include <unistd.h>
#include <thread>
using namespace std::chrono_literals;

int main(int argc, char *argv[]) {
    auto start = std::chrono::system_clock::now();

    // std::this_thread::sleep_for(4s);
    // sleep(1);

    auto end = std::chrono::system_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time spent: "
              << double(duration.count()) *
                     std::chrono::microseconds::period::num /
                     std::chrono::microseconds::period::den
              << "s" << std::endl;

    return 0;
}
