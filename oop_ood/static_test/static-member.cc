#include <iostream>
class P {
public:
    static const int size = 10;
    double d[size]; // ok, 可以不在类外定义
    int x;
    void f(int = size) {}
    // void t2(int y = x) {
    //     std::cout << y;
    // } // error: invalid use of non-static data member 'x'
};
const int P::size;
void f(const int& x) { std::cout << x << '\n'; }
void t1() {
    //
    f(P::size);
}

class Q; // 不完整类型
class R {
    // Q q1; // error: field has incomplete type 'Q'
    Q* q2;
    Q& q3 = *q2;
    static Q q4;
    // ------------------------------------------------
    // R r1; // error: field has incomplete type 'R'
    static R r2;
    R* r3;
    R& r4 = *r3;
};
int main(int argc, char* argv[]) {
    // t1();

    return 0;
}
