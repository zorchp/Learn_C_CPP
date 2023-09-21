#include <bits/stdc++.h>
using namespace std;


class B {
public:
    virtual void f() { cout << "f()\n"; }
};

void t1() {
    B b;
    b.f();
    (&b)->f();
}

void t2() {
    auto pb = new B;
    pb->f();
}

void t3() {
    B b;
    B& rb = b;
    rb.f();
}


int main(int argc, char* argv[]) {
    t1();
    return 0;
}
