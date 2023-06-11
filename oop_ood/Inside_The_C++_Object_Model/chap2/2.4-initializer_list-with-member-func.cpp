#include <iostream>


using namespace std;


class X {
public:
    int i;
    int j;
    X(int val) : i(xfoo(val)), j(val) {}
    int xfoo(int val) { return 1 + val; }
};


void t1() {
    X x(1);
    cout << x.i << endl; // 2
    cout << x.j << endl; // 1
}

class Y : public X {
public:
    int _fval;

    int fval() { return _fval; }
    Y(int val) : _fval(val), X(fval()) {}
    // warning: field '_fval' will be initialized after base 'X'
    // [-Wreorder-ctor]
};

void t2() {
    Y y(2);
    cout << y._fval << endl; // 2
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
