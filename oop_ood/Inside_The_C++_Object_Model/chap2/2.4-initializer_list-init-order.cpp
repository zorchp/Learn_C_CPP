#include <iostream>

using namespace std;

class X {
public:
    int i;
    int j;
    X(int val) : j(val), i(j) {}
    // warning: field 'j' will be initialized after field 'i' [-Wreorder-ctor]
    // warning: field 'j' is uninitialized when used here [-Wuninitialized]
};

void t1() {
    X x(21);
    cout << x.i << endl; // 1, this is default val
    cout << x.j << endl; // 21
}

class Y {
public:
    int i;
    int j;
    Y(int val) : j(val) { i = j; }
    // warning: field 'j' will be initialized after field 'i' [-Wreorder-ctor]
    // warning: field 'j' is uninitialized when used here [-Wuninitialized]
};

void t2() {
    Y y(21);
    cout << y.i << endl; // 21
    cout << y.j << endl; // 21
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
