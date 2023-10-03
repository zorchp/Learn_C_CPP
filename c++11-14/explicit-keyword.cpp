#include <bits/stdc++.h>
using namespace std;

struct Complex {
    int real, imag;
    explicit // 加上之后只能显式转换
        Complex(int re, int im = 0)
        : real(re), imag(im) {}

    Complex operator+(const Complex& x) {
        return Complex((real + x.real), (imag + x.imag));
    }
};

ostream& operator<<(ostream& os, Complex c) {
    os << c.real << "+" << c.imag << "i" << endl;
    return os;
}

void t1() {
    Complex c1(12, 5), c3(5, 0);
    cout << c1;
    // Complex c2 = c1 + 5;//error
    Complex c2 = c1 + Complex(2, 0) + c3;
    cout << c2;
}

class P {
public:
    P(int a, int b) { cout << "P(int a,int b) \n"; }

    // P(initializer_list<int>) {
    //     cout << "P(initializer_list<int> \n";
    // }

    explicit P(int a, int b, int c) {
        cout << "explicit P(int a,int b,int c) \n";
    }
};
void fp(const P) {}

void t2() {
    P p1(3, 4);
    P p2{3, 4};
    P p3{2, 1, 2};
    P p4 = {2, 3};
    // P p5 = {2, 3, 4}; // error without initializer_list<int> ctor
    P p6(2, 3, 4);
}
void t3() {
    fp({2, 3});
    // fp({3, 4, 5}); // error without initializer_list<int> ctor
    fp(P{2, 3});
    fp(P{2, 3, 4});
}

int main(int argc, char const* argv[]) {
    // t1();
    t2();
    // t3();
    return 0;
}