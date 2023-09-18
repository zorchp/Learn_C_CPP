#include <bits/stdc++.h>
using namespace std;

namespace NonVirtual {

class A {
public:
    A() { cout << "A()\n"; }
    ~A() { cout << "~A()\n"; }
};

class B : public A {
public:
    B() { cout << "B()\n"; }
    ~B() { cout << "~B()\n"; }
};

} // namespace NonVirtual


namespace Virtual {

class A {
public:
    A() { cout << "A()\n"; }
    virtual ~A() { cout << "~A()\n"; }
};

class B : public A {
public:
    B() { cout << "B()\n"; }
    ~B() { cout << "~B()\n"; }
};

} // namespace Virtual

void t1() {
    using namespace Virtual;
    // using namespace NonVirtual;
    A* pb = new B;
    //
    delete pb;
    /*
    A()
    B()
    ~B()
    ~A()*/
}

int main() {
    //
    t1();
    return 0;
}
