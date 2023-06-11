#include <iostream>

class Base {
public:
    void pub_mem();

protected:
    int prot_mem;

private: // 基类中成员的访问说明符
    char priv_mem;
};
// 某个类对其继承来的成员的访问权限 受到两个因素的影响,
// 1. 在基类中该成员的访问说明符
// 2. 在派生类的派生列表中的访问说明符

struct Pub_Derv : public Base {  // 派生列表中的访问说明符
    int f() { return prot_mem; } // 派生类可以访问 protected 成员
    // char g() { return priv_mem; } // 不可访问 private 成员
    void h() { pub_mem(); } // ok
};

// 对基类成员的访问权限只与基类中的访问说明符有关
struct Priv_Derv : private Base {
    int f() const { return prot_mem; }
    // char g() { return priv_mem; } // 不可访问 private 成员
    void h() { pub_mem(); } // ok
};

struct Prot_Derv : protected Base {
    // Base 的所有公有成员在本类中都是受保护的
    int f() const { return prot_mem; }
    // char g() { return priv_mem; } // 不可访问 private 成员
    void h() { pub_mem(); } // ok
};

// 派生访问说明符的目的是控制派生类用户(包括派生类的派生类..)对于基类成员的访问权限

void t1() {
    Pub_Derv d1;
    d1.pub_mem();
    // std::cout << d1.f();
    Priv_Derv d2;
    // d2.pub_mem(); // private, 不能访问
    Prot_Derv d3;
    // d3.pub_mem(); // protected, 不能访问
}

// 派生访问说明符还可以控制继承自派生类的新类的访问权限
struct Derived_from_Public : public Pub_Derv {
    // ok, Base::prot_mem 在 Pub_Derv 中仍然是 protected 的
    int use_base() { return prot_mem; }
};

struct Derived_from_Protected : public Prot_Derv {
    // ok, Base::prot_mem 在 Pub_Derv 中仍然是 protected 的
    int use_base() { return prot_mem; }
};


struct Derived_from_Private : public Priv_Derv {
    // error, Base::prot_mem 在 Priv_Derv 中是 private 的
    // int use_base() { return prot_mem; }
};

// 私有继承导致派生类私有化了所有基类成员,
// 所以这个类作为基类时派生出的类不能访问该类的成员
//(以及该类的父类的成员)
