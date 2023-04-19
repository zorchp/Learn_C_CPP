
// C++ Program to demonstrate a pure virtual destructor
#include <iostream>
using namespace std;

// Initialization of base class
class Base {
public:
    virtual ~Base() = 0;
    // Pure virtual destructor
};

// 需要有定义, 否则就link error
Base::~Base() { cout << "~Base\n"; }

// Initialization of derived class
class Derived : public Base {
public:
    ~Derived() { cout << "~Derived() is executed\n"; }
};

void t1() {
    // base class pointer which is
    // allocating fresh storage
    // for Derived function object's
    Base* b = new Derived();
    delete b;
    // ~Derived() is executed
    // ~Base
}

void t2() {
    Base* b = new Derived[2];
    delete[] b;
}

// Driver Code
int main() {
    // t1();
    t2();
    return 0;
}