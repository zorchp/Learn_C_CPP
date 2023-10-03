#include <chrono>
#include <iostream>
#include <format>
#include <mutex>
#include <thread>

using namespace std;

mutex output_lock;
void func(const char* name) {
    // this_thread::sleep_for(100ms);
    // lock_guard<mutex> guard{output_lock};
    cout << format("thread {}\n", name);
    // cout << "thread " << name << '\n';
}

int main(int argc, char* argv[]) {
    thread t1{func, "A"};
    thread t2{func, "B"};
    t1.join();
    t2.join();
    return 0;
}
