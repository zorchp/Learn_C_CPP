#include <iostream>
#include <chrono>
#include <thread>
#include <format>
using namespace std;

void show() {
    auto raw_time = chrono::utc_clock::now();
    auto time_fmt = format("{0:%F} {0:%R}:{0:%S}", raw_time);
    cout << time_fmt << '\r' << flush; // just for G++
    this_thread::sleep_for(1s);
}

int main(int argc, char *argv[]) {
    while (1)
        show();
    return 0;
}
