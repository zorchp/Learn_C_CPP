#include <iostream>

using namespace std;

class A {
public:
    void f1();              // non virtual func
    virtual void vf1();     // virtual func
    virtual void vf2() = 0; // pure-virtual func

private:
    int m_a;
};

void A::f1() { cout << "A call f1" << endl; }
void A::vf1() { cout << "A call vf1" << endl; }
void A::vf2() { cout << "A call vf2" << endl; }


class B : public A {
public:
    void f1() { cout << "B call f1" << endl; }
    void f2();
    // void vf1();  // declare the vfunc, and you must define
    void vf2();

private:
    int m_b;
};

// void B::vf1() { cout<<"B call vf1"<<endl; }

void B::vf2() { cout << "B call vf2" << endl; }


// void test1() {
//     A a;
//     a.vf1();
// }

void test2() {
    B b;
    b.f1();
    b.vf1();
    b.vf2();
}

int main(int argc, char const *argv[]) {
    // test1();
    test2();
    return 0;
}