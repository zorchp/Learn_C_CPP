#include <cstdio>

class A {
public:
    A() { printf("A"); }
    virtual ~A() = 0;
};
A::~A() { printf("~A"); }

class B : public A {
public:
    B() { printf("B"); }
    ~B() { printf("~B"); }
};

void t1() {
    A* a = new B;
    delete a; // AB~B~A
}
void t2() {
    A* c = new B[2];
    delete[] c; // ABAB~A~A
}

int main() {
    // t1();
    t2();
    return 0;
}