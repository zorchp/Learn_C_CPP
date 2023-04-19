#include <iostream>
using namespace std;
template <typename T, typename U>
void PerfectForward(T&& t, U& Func) {
    cout << t << "\tforwarded..." << endl;
    // Func(std::forward<T>(t));
    Func(static_cast<T&&>(t));
}
void RunCode(double&& m) {}
void RunHome(double&& h) {}
void RunComp(double&& c) {}
int main() {
    PerfectForward(1.5, RunComp); // 1.5      forwarded...
    PerfectForward(8, RunCode);   // 8         forwarded...
    PerfectForward(1.5, RunHome); // 1.5      forwarded...
}
// 编译选项: g++ -std=c++11 3-3-10.cpp
