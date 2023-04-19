#include <bits/stdc++.h>
using namespace std;

class Base {
public:
    Base() { cout << "ctor, base." << endl; }
    ~Base() { cout << "dctor, base." << endl; }
};


class Component {
public:
    Component() { cout << "ctor, Component." << endl; }
    ~Component() { cout << "dctor, Component." << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "ctor, Derived." << endl; }
    ~Derived() { cout << "dctor, Derived." << endl; }

protected:
    Component c; //子类有复合关系
};


int main(int argc, char const *argv[]) {
    Derived d1;
    return 0;
}
//先父类再复合最后子类(派生类)
/*

构造由内而外,析构由外而内
ctor, base.
ctor, Component.
ctor, Derived.
dctor, Derived.
dctor, Component.
dctor, base.
[Finished in 587ms]
*/