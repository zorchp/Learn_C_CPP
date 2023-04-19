#include <iostream>
using namespace std;
struct A {
    A() { cout << "A::A()\n"; }
    A(int i) { cout << "A::A(int)\n"; }
};
struct B : A {
    B() { cout << "B::B()\n"; }
    /* B(int i) : d(i) { cout << "B::B(int)\n"; } */
    B(int i) : A(i), d(i) { cout << "B::B(int)\n"; } // 先初始化A再构造B
    int d;
};
void t1() {
    B b;
    /* A::A() */
    /* B::B() */
}
void t2() {
    B b(10);
    /* A::A(int) */
    /* B::B(int) */
}
int main(int argc, char *argv[]) {
    /* t1(); */
    t2();
    return 0;
}
