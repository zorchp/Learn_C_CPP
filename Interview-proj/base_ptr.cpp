#include <iostream>

using namespace std;

class B {
public:
    virtual void f() { cout << "B\n"; }
};

class D : public B {
public:
    virtual void f() { cout << "D\n"; }
};

void t1() {
    B *pb = new D;
    pb->f();    // D
    pb->B::f(); // B
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
