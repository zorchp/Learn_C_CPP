#include <bits/stdc++.h>
using namespace std;


struct Base {
    virtual void vfunc(float) {}
};

struct Derived1 : Base {
    virtual void vfunc(int) {}
};

struct Derived2 : Base {
    // virtual void vfunc(int) override {}
    virtual void vfunc(float) override {}
};


void t1() {}

struct Base1 final {};
//针对类
// struct Derived3: Base1 {};//不可被继承

//针对虚函数
struct Base2 {
    virtual void vf() final;
};

struct Derived4 : Base2 {
    //不允许被覆写
    // void vf();
};


int main(int argc, char const *argv[]) {
    t1();
    return 0;
}