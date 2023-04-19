#include <iostream>

using namespace std;

class P {
public:
    P() = default;
    void t() { cout << "call void t();\n"; }
    // int t() {
    //     cout << "call int t();\n";
    //     return 1;
    // }
    // error: 'int P::t()' cannot be overloaded with 'void P::t()'
    void t() const { cout << "call t() const\n"; }
    void t(int) { cout << "call t(int)\n"; }
    void t(int) const { cout << "call t(int) const\n"; }
};

void t1() {
    P p;
    p.t();
    p.t(1);
    // call t()
    // call t(int)
}

void t2() {
    const P p;
    p.t();
    p.t(1);
    // call t() const
    // call t(int) const
}

void t3() {
    P p;
    // 常量左值引用
    const P &cp = p;
    cp.t();
    cp.t(1);
    // call t() const
    // call t(int) const
}

void t4() {
    P p;
    // 常量右值引用
    const P &&cp = move(p);
    cp.t(); // call t() const
}

void t5() {
    P p;
    const P &cp(p);
    const_cast<const P &>(cp).t(); // call t() const
}

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    // t3();
    // t4();
    t5();
    return 0;
}