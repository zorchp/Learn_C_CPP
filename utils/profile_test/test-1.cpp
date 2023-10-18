#include <gperftools/profiler.h>
#include <iostream>
#include <thread>
#include <string>
using namespace std;


void t1() {
    auto p = new string[12];
    this_thread::sleep_for(1s);
    // for (;;)
    //     ;
    delete[] p;
}

int main() {
    ProfilerStart("aa.prof");
    t1();
    ProfilerStop();
    return 0;
}
