#include <iostream>
using namespace std;

struct A {
    A() { cout << "A::A()\n"; }
    A(int) { cout << "A::A(int)\n"; }
};
struct B {
    B() { cout << "B::B()\n"; }
    B(int) { cout << "B::B(int)\n"; }
};

struct C : A, B {
    using A::A;
    using B::B;
    C(int a) { cout << "C::C(int)\n"; }
};
void t1() {
    C c; // only for clang
    /* A::A() */
    /* B::B() */
}

void t2() {
    /* C c(1); // */
    /* A::A() */
    /* B::B() */
    /* C::C(int) */
}
int main(int argc, char *argv[]) {
    t1();
    /* t2(); */
    return 0;
}
