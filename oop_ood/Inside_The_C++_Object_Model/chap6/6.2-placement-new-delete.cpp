#include <iostream>
struct B {
    virtual ~B() {}
    int j;
    virtual void f() { std::cout << "B::f\n"; }
};

struct D : B {
    void f() { std::cout << "D::f\n"; }
};

void t1() {
    B b;
    b.f(); // B::f
    b.~B();
    new (&b) D; // placement new
    b.f();      // B::f
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
