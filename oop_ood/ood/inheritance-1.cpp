#include <bits/stdc++.h>
using namespace std;

class Base {
public:
    Base() { cout << "ctor, base." << endl; }
    ~Base() { cout << "dctor, base." << endl; }
};


class Derived : public Base {
public:
    Derived();
    ~Derived();
};

Derived::Derived() : Base() { cout << "ctor, Derived." << endl; }
Derived::~Derived() {
    // Base::~Base();// 编译器已经加上这句了
    cout << "dctor, Derived." << endl;
}


int main(int argc, char const *argv[]) {
    Derived d1;
    return 0;
}

/*

构造由内而外,析构由外而内
ctor, base.
ctor, Derived.
dctor, Derived.
dctor, base.
*/