#include <bits/stdc++.h>

using namespace std;

class Fraction {
public:
    // 非显式单一参数构造函数
    Fraction(int num, int den = 1) : m_num(num), m_den(den) {}
    // 转换函数: 没有参数以及返回类型
    operator double() const { return (double)m_num / m_den; }
    // 第二种方法, 重载+运算符
    Fraction operator+(const Fraction& f) {
        return Fraction(f.m_num * m_den + m_num, m_den);
        // return f;
    }

private:
    int m_num, m_den;
};


int main(int argc, char const* argv[]) {
    Fraction f1(3, 5), f2(3, 7);
    // cout<<(double)f1<<endl;
    Fraction ret = 4 + f2;
    cout << ret << endl;
    return 0;
}
