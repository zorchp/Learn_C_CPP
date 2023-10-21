#include <gperftools/profiler.h>
#include <iostream>
#include <thread>
#include <vector>
#include <string>
using namespace std;

vector<int> v;

void t1() {
    auto p = new string[12];
    for (int i{}; i < 100000000; ++i) {
        v.push_back(i);
    }

    // this_thread::sleep_for(1s);
    // for (;;)
    //     ;
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    delete[] p;
}

int main() {
    ProfilerStart("aa.prof");
    t1();
    ProfilerStop();
    return 0;
}
