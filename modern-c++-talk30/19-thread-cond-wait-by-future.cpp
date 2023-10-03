#include <chrono>
#include <iostream>
#include <future>
#include <thread>

using namespace std;

int work() {
    this_thread::sleep_for(2s);
    return 42;
}

int main(int argc, char *argv[]) {
    auto fut = async(launch::async, work);
    cout << "waiting...\n";
    cout << "ans = " << fut.get() << endl;
    return 0;
}
