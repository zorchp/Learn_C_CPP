#include <iostream>
class B {
public:
    B() { std::cout << "B::B()\n"; }
    virtual void f() = 0;
    virtual ~B() = 0;
};

B::~B() { std::cout << "B::~B()\n"; }

void B::f() { std::cout << "B::f()\n"; }

class D : public B {
public:
    void f() { std::cout << "D::f()\n"; }
};

void t1() {
    // B b; // can not be instantiated
    D d;
    d.f();
    d.B::f();
}

void t2() {
    // polymorphic
    B *pb = new D;
    pb->f();
    pb->B::f();
}

void t3() {
    // polymorphic
    D d;
    B &rb = d;
    rb.B::f();
    rb.f();
}

int main(int argc, char *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}
