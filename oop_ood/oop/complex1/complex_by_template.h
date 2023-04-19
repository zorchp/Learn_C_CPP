// 防卫式声明
#ifndef __COMPLEX__
#define __COMPLEX__
// ----- 前置声明 -----

template <typename T>
class complex;

// 标准库函数: do assignment plus
template <typename T>
complex<T> &__doapl(complex<T> *ths, const complex<T> &r);

template <typename T>
inline complex<T> &__doapl(complex<T> *ths, const complex<T> &r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

// ----- 类的声明 -----
// 采用模板
template <typename T>
class complex {
public:
    // 构造函数(函数名要与类名相同)
    complex(T r = 0, T i = 0) : re(r), im(i) {}

    complex &operator+=(const complex &);

    T real() const { return re; }

    T imag() const { return im; }

private:
    T re, im;

    // 友元
    friend complex &__doapl<>(complex *ths, const complex &r);
};

// 使用内联函数加快编译速度
template <typename T>
inline T real(const complex<T> &r) {
    return r.real();
}

template <typename T>
inline T imag(const complex<T> &r) {
    return r.imag();
}

template <typename T>
inline complex<T> &complex<T>::operator+=(const complex<T> &r) {
    return __doapl(this, r);
}

#endif