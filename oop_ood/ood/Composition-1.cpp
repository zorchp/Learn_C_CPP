#include <bits/stdc++.h>
using namespace std;


class Component {
public:
    Component() { cout << "ctor, Component." << endl; }
    ~Component() { cout << "dctor, Component." << endl; }
};

class Derived {
public:
    Derived() { cout << "ctor, Derived." << endl; }
    ~Derived() { cout << "dctor, Derived." << endl; }

protected:
    Component c;
};


int main(int argc, char const *argv[]) {
    Derived d1;
    return 0;
}

/*
构造由内而外,析构由外而内
ctor, Component.
ctor, Derived.
dctor, Derived.
dctor, Component.
*/