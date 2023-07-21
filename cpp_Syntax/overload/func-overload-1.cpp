#include <iostream>

using namespace std;

int f1();
// double f1();
// Functions that differ only in their return type cannot be overloaded

int f1(int); // overloaded, number of args is different

void f2(int, float);
void f2(float, int); // overloaded, order of args is different

void f3(int);
void f3(double); // type of args is different

int f4(int) { return int{}; }
float f4(float) { return float{1}; } // ok, overloaded by different type
// even though return type is different

void t1() {
    //
    using pf41 = int (*)(int);
    using pf42 = float (*)(float);
    cout << typeid(pf41).name() << endl; // PFiiE
    cout << typeid(pf42).name() << endl; // PFffE
    pf41 p1 = f4;
    pf42 p2 = f4;
    cout << typeid(p1).name() << endl; // PFiiE
    cout << typeid(p2).name() << endl; // PFffE
    cout << p1(0) << endl;
    cout << p2(0) << endl;
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
