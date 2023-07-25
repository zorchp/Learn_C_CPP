#include <iostream>
using namespace std;
struct A {
    A(int i) {}
    A(double d, int i) {}
    A(float f, int i, const char* c) {}
    // ...
};
struct B : A {
    using A::A;
    int d{0};
};
int main() {
    B b(356);            // b.d被初始化为0
    cout << b.d << endl; // 0
}
