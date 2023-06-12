#include <cstdio>
#include <iostream>
using namespace std;

class P {
public:
    double f() { return 3.14; }
    // double f() { return 1 - x; }
    void g() { printf("%p\n", &P::f); }
    int x{};
};
using pfunc = double (P::*)();
using px = int P::*;

void t1() {
    pfunc pf = &P::f;
    printf("%p\n", pf); // same
    P().g();            // same
    P p;
    p.g(); // same
}
void t2() {
    P p;
    P *pp = 0;
    pfunc pf = &P::f;
    printf("&p=%p\n", &p);
    printf("&pf=%p\n", &pf);
    printf("%.2f\n", (p.*pf)());
    printf("%.2f\n", (pp->*pf)());
    // &p=0x16b81a990
    // &pf=0x16b81a940
    // 3.14
    // 3.14
}

class Q {
public:
    Q() : _z(1.2) {}
    virtual float z() { return _z; }
    virtual float x() { return _z; }
    virtual ~Q();

private:
    float _z;
};
Q::~Q() {
    //
}

void t3() {
    float (Q::*pmf)() = &Q::z;
    Q *p = new Q;
    cout << p->z() << endl;      // 1.2
    cout << (p->*pmf)() << endl; // 1.2
    delete p;
}

void t4() {                      //
    printf("&Q::z=%p\n", &Q::z); // 0x0
    printf("&Q::x=%p\n", &Q::x); // 0x8, 正好是一根虚指针
}

int main(int argc, char *argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}
