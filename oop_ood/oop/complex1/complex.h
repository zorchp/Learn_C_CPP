// 防卫式声明
#ifndef __COMPLEX__
#define __COMPLEX__
// ----- 前置声明 -----

class complex;

// 标准库函数: do assignment plus
complex &__doapl(complex *ths, const complex &r);

complex &__doami(complex *ths, const complex &r);

complex &__doaml(complex *ths, const complex &r);

// ----- 类的声明 -----
// 采用模板
// template<typename T>
class complex {
public:
    // 构造函数(函数名要与类名相同)
    complex(double r = 0, double i = 0) : re(r), im(i) {}

    complex &operator+=(const complex &);

    complex &operator-=(const complex &);

    complex &operator*=(const complex &);

    complex &operator/=(const complex &);

    double real() const { return re; }

    double imag() const { return im; }

private:
    double re, im;

    friend complex &__doapl(complex *ths, const complex &r);

    friend complex &__doami(complex *ths, const complex &r);

    friend complex &__doaml(complex *ths, const complex &r);
};

inline double real(const complex &r) { return r.real(); }

inline double imag(const complex &r) { return r.imag(); }

inline complex &__doapl(complex *ths, const complex &r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex &complex::operator+=(const complex &r) {
    return __doapl(this, r);
}

inline complex &__doami(complex *ths, const complex &r) {
    ths->re -= r.re;
    ths->im -= r.im;
    return *ths;
}

inline complex &complex::operator-=(const complex &r) {
    return __doami(this, r);
}

inline complex &__doaml(complex *ths, const complex &r) {
    double tmp = ths->re * r.im + ths->im * r.re;
    ths->re    = r.re * ths->re - r.im * ths->im;
    ths->im    = tmp;
    return *ths;
}

inline complex &complex::operator*=(const complex &r) {
    return __doaml(this, r);
}

inline complex operator+(const complex &x, const complex &y) {
    return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex operator+(const complex &x, double y) {
    return complex(real(x) + y, imag(x));
}

inline complex operator+(double x, const complex &y) {
    return complex(x + real(y), imag(y));
}

inline complex operator-(const complex &x, const complex &y) {
    return complex(real(x) - real(y), imag(x) - imag(y));
}

inline complex operator-(const complex &x, double y) {
    return complex(real(x) - y, imag(x));
}

inline complex operator-(double x, const complex &y) {
    return complex(x - real(y), -imag(y));
}

inline complex operator*(const complex &x, const complex &y) {
    return complex(real(x) * real(y) - imag(x) * imag(y),
                   real(x) * imag(y) + real(y) * imag(x));
}

inline complex operator*(const complex &x, double y) {
    return complex(real(x) * y, imag(x) * y);
}

inline complex operator*(double x, const complex &y) {
    return complex(x * real(y), x * imag(y));
}

inline complex operator/(const complex &x, double y) {
    return complex(real(x) / y, imag(x) / y);
}

inline complex operator+(const complex &x) { return x; }

inline complex operator-(const complex &x) {
    return complex(-real(x), -imag(x));
}

#include <cmath>

inline complex polar(double r, double t) {
    return complex(r * cos(t), r * sin(t));
}

inline complex conj(const complex &x) { return complex(real(x), -imag(x)); }

inline double norm(const complex &x) {
    return real(x) * real(x) + imag(x) * imag(x);
}

inline complex operator/(const complex &x, const complex &y) {
    return x * conj(y) / norm(y);
}

#include <iostream>

using namespace std;

// 格式化输出复数
// 重载 << 运算符
// cout是ostream对象
ostream &operator<<(ostream &os, const complex &x) {
    if (imag(x) < 0)
        return os << real(x) << '-' << -imag(x) << 'i';
    else
        return os << real(x) << '+' << imag(x) << 'i';
}

#endif
