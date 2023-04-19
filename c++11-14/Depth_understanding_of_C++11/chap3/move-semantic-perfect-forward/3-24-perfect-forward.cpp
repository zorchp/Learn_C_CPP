#include <iostream>
using namespace std;
void RunCode(int &&m) { cout << "rvalue ref" << endl; }
void RunCode(int &m) { cout << "lvalue ref" << endl; }
void RunCode(const int &&m) { cout << "const rvalue ref" << endl; }
void RunCode(const int &m) { cout << "const lvalue ref" << endl; }
template <typename T>
void PerfectForward(T &&t) {
    // RunCode(std::forward<T>(t));
    RunCode(static_cast<T &&>(t));
}
int main() {
    int a{};
    int b{};
    const int c = 1;
    const int d = 0;
    PerfectForward(a);            // lvalue ref
    PerfectForward(std::move(b)); // rvalue ref
    PerfectForward(c);            // const lvalue ref
    PerfectForward(std::move(d)); // const rvalue ref
}
// 编译选项:g++ -std=c++11 3-3-9.cpp
