#include <iostream>
using namespace std;
class Base {
public:
    void f() { cout << "Base::f()" << endl; }
};

class Derived : public Base {
public:
    void f() { cout << "Derived::f()" << endl; }
};
/* 对同一个派生类对象调用同样的函数，返回的结果是不一样的 */
/*
   普通的非虚函数体在编译期就与函数调用绑定，指针的类型决定了哪个函数被调用
   通过Base*调用的f一定是基类的，而通过Derived*调用的f一定是派生类的。
 */
int main() {
    Derived d;
    Base *pb = &d;
    // Base::f()
    pb->f();
    Derived *pd = &d;
    // Derived::f()
    pd->f();
}
