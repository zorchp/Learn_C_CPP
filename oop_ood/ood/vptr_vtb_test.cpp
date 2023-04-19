#include <iostream>

using namespace std;

class A {
public:
    virtual void vfunc1();
    virtual void vfunc2(); // vptr:64位电脑:8字节, 所以A:16字节
    void func1();
    void func2();

private:
    int m_data1, m_data2; //占用4*2=8字节
};
// 类外实现
void A::vfunc1() { cout << "A::vfunc1()" << endl; }
void A::vfunc2() { cout << "A::vfunc2()" << endl; }
/*
继承: 包括数据的继承和函数的继承
函数继承: 继承下来的是调用权
*/
class B : public A {
public:
    virtual void vfunc1();
    void func2();

private:
    int m_data3;
};

void B::vfunc1() { cout << "B::vfunc1()" << endl; }

class C : public B {
public:
    virtual void vfunc1();
    void func2();

private:
    int m_data1, m_data4;
};
void C::vfunc1() { cout << "C::vfunc1()" << endl; }

void test1() {
    // A t1;
    // cout << sizeof(t1) << endl;//16
    // 虚函数: 动态绑定(dynamic bind)
    // C: (*(p->vptr)[n])(p);
    // 用虚表(虚机制), 值只能通过p来看
    // 1. 通过指针
    // 2. 指针向上转型up-cast
    // 3. 调用虚函数
    B b;
    A a = (A)b;
    a.vfunc1();

    A* pa = new B; // up-cast
    pa->vfunc1();

    C c;
    A* ppa = &c;
    ppa->vfunc1();
}
/*
A::vfunc1()
B::vfunc1()
C::vfunc1()
Press ENTER to exit!
*/

int main(int argc, char const* argv[]) {
    test1();
    return 0;
}
