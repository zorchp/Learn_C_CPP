#include "complex.h"

#include <iostream>

using namespace std;

// // 格式化输出复数
// // 重载 << 运算符
// // cout是ostream对象
// ostream&
// operator << (ostream& os, const complex& x)
// {
//     if (imag(x)<0)
//         return os << real (x) << '-' << -imag (x) <<'i';
//     else
//         return os << real (x) << '+' << imag (x) << 'i';
// }

void test1() {
    complex c1(1, 2);
    complex c2(2, 2);
    cout << c2 / c1 << endl;
    // complex c1(2, 1);
    // complex c2(4, 0);

    // cout << c1 << endl;
    // cout << c2 << endl;
    // 重载操作符
    // cout << c1+c2 << endl;
    // cout << c1-c2 << endl;
    // cout << c1*c2 << endl;
    // cout << c1 / 2 << endl;

    // cout << conj(c1) << endl;
    // cout << norm(c1) << endl;
    // cout << polar(10,4) << endl;

    // cout << (c1 += c2) << endl;

    // cout << (c1 == c2) << endl;
    // cout << (c1 != c2) << endl;
    // cout << +c2 << endl;
    // cout << -c2 << endl;

    // cout << (c2 - 2) << endl;
    // cout << (5 + c2) << endl;
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}