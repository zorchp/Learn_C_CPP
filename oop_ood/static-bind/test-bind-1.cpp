#include <iostream>

class A {
public:
    // void func() { std::cout << "A::func()\n"; }
    virtual void func() { std::cout << "A::func()\n"; }
};

class B : public A {
public:
    void func() { std::cout << "B::func()\n"; }
};

class C : public A {
public:
    void func() { std::cout << "C::func()\n"; }
};

void t1() {
    C* pc = new C(); // pc的静态类型是它声明的类型C*，动态类型也是C*；
    B* pb = new B(); // pb的静态类型和动态类型也都是B*；
    A* pa = pc;
    // pa的静态类型是它声明的类型A*，动态类型是pa所指向的对象pc的类型C*；
    pa = pb;
    // pa的动态类型可以更改，现在它的动态类型是B*，但其静态类型仍是声明时候的A*；
    C* pnull = NULL;
    // pnull的静态类型是它声明的类型C*,没有动态类型，因为它指向了NULL；

    pa->func(); // A::func()
                // pa的静态类型永远都是A*，不管其指向的是哪个子类，都是直接调用A::func()；
    pc->func(); // C::func() pc的动、静态类型都是C*，因此调用C::func()；
    pnull->func();
    // C::func()
    // 不用奇怪为什么空指针也可以调用函数，因为这在编译期就确定了，和指针空不空没关系；


    pa->func(); // B::func()
                // 因为有了virtual虚函数特性，pa的动态类型指向B*，因此先在B中查找，找到后直接调用；
    pc->func(); // C::func() pc的动、静态类型都是C*，因此也是先在C中查找；
    // pnull
        // ->func(); // 空指针异常，因为是func是virtual函数，因此对func的调用只能等到运行期才能确定，然后才发现pnull是空指针；
}

int main(int argc, char const* argv[]) {
    t1();
    // t2();
    return 0;
}
