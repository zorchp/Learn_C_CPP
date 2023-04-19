#include <iostream>
using namespace std;

void t1() {
    const int &r = 7; // OK
    // It's legal since when a compiler sees const, it converts 7 to an lvalue,
    // and then assign it to the reference.
}

void t2() {
    int &&a = 100;
    cout << a << endl;
    int &b = a;
    cout << b << endl;
}

int square(int &x) { return x * x; }
void t3() {

    int i = 7;
    square(i); // OK
    // square(7); // error, 7 is an rvalue and cannot be assigned to a reference
    // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue
    // of type 'int'
}
int square_const(const int &x) { return x * x; }
void t4() {
    int i = 7;
    cout << square_const(i) << endl; // 49
    cout << square_const(7) << endl; // 49
}
int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}