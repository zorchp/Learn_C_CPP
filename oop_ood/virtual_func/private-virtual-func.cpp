#include <iostream>

#if __WORDSIZE == 64
using TYPE = unsigned long long;
#else
using TYPE = int;
#endif

class B {
private:
    virtual void f() { std::cout << "B::f()\n"; }
};


class D : public B {
public:
    void f() override { std::cout << "D::f()\n"; }
};

using FUNC = void (*)();

void t1() {
    D d;
    d.f(); // D::f()
}

void t2() {
    B *pb [[maybe_unused]] = new D;
    // 由于 private, 不能实现多态
    // pb->f();
}

void t3() {
    D d;
    TYPE pvtbl = *(TYPE *)(&d);
    TYPE pf = *((TYPE *)pvtbl);
    FUNC f = (FUNC)pf;
    f(); // D::f()
}

void t4() {
    B b;
    TYPE pvtbl = *(TYPE *)&b;
    TYPE pf = *((TYPE *)pvtbl);
    FUNC f = (FUNC)pf;
    f(); // B::f()
}

void t5() {
    B b;
    TYPE pvtbl = *(TYPE *)&b;
    FUNC f = *((FUNC *)pvtbl);
    f(); // B::f()
}

int main(int argc, char *argv[]) {
    // t1();
    // t2();
    // t3();
    // t4();
    t5();

    return 0;
}
