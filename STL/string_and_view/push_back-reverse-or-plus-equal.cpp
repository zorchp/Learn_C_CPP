#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <string>
using namespace std;
using namespace std::chrono;
#define MAX 100000
string s1{}, s2{};


void t1() {
    for (int i{}; i < MAX; ++i) s1 = static_cast<char>(i % 127) + s1;
}

void t2() {
    for (int i{}; i < MAX; ++i) s2.push_back(static_cast<char>(i % 127));
    reverse(s2.begin(), s2.end());
}

int main() {
    //
    assert(s1 == s2);
    auto start = system_clock::now();
    t1(); // Time spent: 2.48452s
    t2(); // Time spent: 0.006175s
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time spent: "
         << double(duration.count()) * microseconds::period::num /
                microseconds::period::den
         << "s" << endl;


    assert(s1 == s2);
}
