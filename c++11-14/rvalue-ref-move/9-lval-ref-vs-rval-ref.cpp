#include <iostream>
using namespace std;

namespace t1 {
class X {
public:
    X() {}
    X(const X&) {}
    // error: cannot bind non-const lvalue reference of type 'X&' to an rvalue
    // of type 'X'
    // X& operator=(X&) { return *this; }
    X& operator=(const X&) { return *this; }
};

X make_x() { return X(); }

void t() {
    X x1;
    X x2(x1);
    X x3(make_x());
    x3 = make_x();
}
} // namespace t1

namespace t2 {
class X {
public:
    X() { std::cout << "X ctor" << std::endl; }
    X(const X& x) { std::cout << "X copy ctor" << std::endl; }
    // X& operator=(const X&) {
    //     std::cout << "X copy assign" << std::endl;
    //     return *this;
    // }
    ~X() { std::cout << "X dtor" << std::endl; }
    void show() { std::cout << "show X" << std::endl; }
};

X make_x() {
    X x1;
    return x1;
}

void t() {
    X&& x2 = make_x();
    x2.show();
    /*
    X ctor
    X copy ctor
    X dtor
    show X
    X dtor*/
    /*第一次是make_x函数中x1的默认构造，第二次是return
     * x1引发的复制构造。不同的是，由于x2是一个右值引用，
     * 引用的对象是函数make_x返回的临时对象，因此该临时对象的生命周期得到延长，
     * 所以我们可以在X &&x2 =
     * make_x()语句结束后继续调用show函数而不会发生任何问题。
     * 对性能敏感的读者应该注意到了，延长临时对象生命周期并不是这里右值引用的最终目标，
     * 其真实目标应该是减少对象复制，提升程序性能。*/
}
void tt() {
    // with `g++ -fno-elide-constructors`: 关闭函数返回值优化（RVO）
    X x2 = make_x();
    x2.show();
    /*X ctor
X copy ctor
X dtor
X copy ctor
X dtor
show X
X dtor*/
    /* 首先make_x函数中x1会默认构造一次,
     * 然后return x1会使用复制构造产生临时对象,
     * 接着X x2 = make_x()会使用复制构造将临时对象复制到x2
     * 最后临时对象被销毁。*/
}
} // namespace t2

int main(int argc, char const* argv[]) {
    // t1::t();
    t2::t();
    cout << "---------------------" << endl;
    t2::tt();
    /*
    X ctor
    X copy ctor
    X dtor
    show X
    X dtor
    ---------------------
    X ctor
    X copy ctor
    X dtor
    X copy ctor
    X dtor
    show X
    X dtor
    */
    return 0;
}