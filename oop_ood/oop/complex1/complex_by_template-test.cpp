#include "complex_by_template.h"

#include <iostream>

using namespace std;

// 格式化输出复数
// 重载 << 运算符
template <typename T>
ostream &operator<<(ostream &os, const complex<T> &x) {
    if (imag(x) < 0)
        return os << real(x) << '-' << -imag(x) << 'i';
    else
        return os << real(x) << '+' << imag(x) << 'i';
}

void test1() {
    complex<int> c1(-3, -3);
    complex<int> c2(3, 2);
    c2 += c1;
    cout << c2 << endl;
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}