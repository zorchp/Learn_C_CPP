#include <iostream>

using namespace std;

// 递归函数不要声明为内联
// inline
int my_gcd(int a, int b) { return b ? my_gcd(b, a / b) : a; }

class P {
public:
    virtual void f();
};
// 虚函数不要声明为内联, 因为编译期并不能知道具体的调用情况
// inline
void P::f() {
    //
}

// 函数体过大不要声明为内联
void big_f() {
    //
    //
    //
    //
    //
    //
}
// 函数指针调用时, 不要声明为内联, 因为编译器不知道具体调用的函数
inline void f() {}
void (*pf)() = f;

void t0() {
    f();  // 内联
    pf(); // 可能内联
}

void t1() {
    cout << my_gcd(30, 12) << endl; // 6
}
int main(int argc, char *argv[]) {
    t1();
    return 0;
}
