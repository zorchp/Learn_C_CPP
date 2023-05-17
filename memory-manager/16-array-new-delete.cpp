#include <iostream>

using namespace std;
class A {
    int i;

public:
    A(int x = 0) : i(x) {}
};

void t1() {
    auto pA = new A[3];
    // delete pA; // just warning
    delete[] pA;
}

class B {
    B* pB;

public:
    B(B* pB_ = 0) : pB(pB_) {}
};

void t2() {
    auto pB = new B[3];
    delete[] pB;
    // delete pB;
    // delete pB;
    // delete pB;
}

int main(int argc, char const* argv[]) {
    // t1();
    t2();
    return 0;
}