#include <bits/stdc++.h>
using namespace std;


template <typename T>
class complex1;

// 标准库函数: do assignment plus
template <typename T>
complex1<T> &__doapl(complex1<T> *ths, const complex1<T> &r);

template <typename T>
inline complex1<T> &__doapl(complex1<T> *ths, const complex1<T> &r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

template <typename T>
class complex1 {
public:
    // 构造函数(函数名要与类名相同)
    complex1(T r = 0, T i = 0) : re(r), im(i) {}

    complex1 &operator+=(const complex1 &);

    T real() const { return re; }

    T imag() const { return im; }

private:
    T re, im;

    // 友元
    friend complex1 &__doapl<>(complex1 *ths, const complex1 &r);
};

// 使用内联函数加快编译速度
template <typename T>
inline T real(const complex1<T> &r) {
    return r.real();
}

template <typename T>
inline T imag(const complex1<T> &r) {
    return r.imag();
}

template <typename T>
inline complex1<T> &complex1<T>::operator+=(const complex1<T> &r) {
    return __doapl(this, r);
}


void t1() {
    complex1<double> c1(2.3, 3.2);
    complex1<int> c2(2, 3), c3(3, 4);
    c2 += c3;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}