#include <iostream>
using namespace std;
struct A {
    A(int i) { cout << "A(int)\n"; }
    A(double d, int i) { cout << "A(double,int)\n"; }
};

struct B : A {
    B(int i) : A(i) { cout << "B(int):A\n"; }
    B(double d, int i) : A(d, i) { cout << "B(double,int):A\n"; }
};

void t1() {
    B b(1);
    B bb(1.1, 1);
    /* A(int) */
    /* B(int):A */
    /* A(double,int) */
    /* B(double,int):A */
}
int main(int argc, char *argv[]) {
    t1();
    return 0;
}
