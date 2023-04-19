#include <bits/stdc++.h>
using namespace std;

class Component {
public:
    Component() { cout << "ctor, Component." << endl; }
    ~Component() { cout << "dctor, Component." << endl; }
};

class Base {
public:
    Base() { cout << "ctor, base." << endl; }
    ~Base() { cout << "dctor, base." << endl; }

protected:
    Component c; //父类具有复合关系
};


class Derived : public Base {
public:
    Derived() { cout << "ctor, Derived." << endl; }
    ~Derived() { cout << "dctor, Derived." << endl; }
};


int main(int argc, char const *argv[]) {
    Derived d1;
    return 0;
}

/*
ctor, Component.
ctor, base.
ctor, Derived.
dctor, Derived.
dctor, base.
dctor, Component.
[Finished in 993ms]
*/