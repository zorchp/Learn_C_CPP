#include <cstdio>
#include <iostream>

class Base {
public:
    std::size_t size() const { return n; }

protected:
    std::size_t n;

private:
    int x;
};

class Derived : private Base {
public:
    using Base::size; // 这样可以保持对象 size 成员的访问级别
    // using Base::x; // 由于派生类访问不到 基类私有成员 x,所以 using 无效

protected:
    using Base::n;
};
// 加上 using 之后, Derived 的对象可以使用 size(),
// 而其派生类可以使用保护对象 n

class P : public Derived {
    size_t f() { return n; }
};

// using 声明语句中名字的访问权限由该 using 声明语句之前的访问说明符来决定,

// 派生类只能为那些它可以访问的名字提供 using 声明

void t1() {
    Derived d;
    std::cout << d.size(); /// ok , by `using`
}
