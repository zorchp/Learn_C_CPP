#include <iostream>
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
    long pvtbl = *(long *)(&d);
    long pf = *((long *)pvtbl);
    FUNC f = (FUNC)pf;
    f(); // D::f()
}

void t4() {
    B b;
    long pvtbl = *(long *)&b;
    long pf = *((long *)pvtbl);
    FUNC f = (FUNC)pf;
    f(); // B::f()
}

int main(int argc, char *argv[]) {
    t1();
    // t2();
    // t3();
    // t4();

    return 0;
}
