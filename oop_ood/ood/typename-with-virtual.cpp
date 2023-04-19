#include <typeinfo>
#include <iostream>
using namespace std;

class Base {};
class Derived : public Base {};

void t1() {
    Base b, *pb;
    pb = NULL;
    Derived d;
    Base *pb2 = dynamic_cast<Base *>(new Derived);
    Base &b2 = d;
    Base *pb3 = &d;
    cout << typeid(pb2).name() << endl   // 输出Base *
         << typeid(b2).name() << endl    // 输出Base
         << typeid(pb3).name() << endl   // 输出Base *
         << typeid(*pb3).name() << endl; // 输出Base
}
// P4Base
// 4Base
// P4Base
// 4Base

// with virtual function
class Base1 {
    virtual void f() {}
};
class Derived1 : public Base1 {};

void t2() {
    //
    Base1 b, *pb{};
    Derived1 d;
    Base1 *pb2 = dynamic_cast<Base1 *>(new Derived1);
    Base1 &b2 = d;
    Base1 *pb3 = &d;
    cout << typeid(pb2).name() << endl   // 输出Base *
         << typeid(b2).name() << endl    // 输出Derived1
         << typeid(pb3).name() << endl   // 输出Base *
         << typeid(*pb3).name() << endl; // 输出Derived1
    // P5Base1
    // 8Derived1
    // P5Base1
    // 8Derived1
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}