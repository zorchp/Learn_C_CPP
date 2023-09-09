#include <cstdio>
#include <iostream>
using namespace std;
class A {
public:
    int x;
    int y;
    virtual void f() { cout << "f() called !" << endl; };
    virtual void f1() { cout << "f1() called !" << endl; };
    virtual void f2() { cout << "f2() called !" << endl; };
    // private:
    void f3() {
        // x = 12;
        // 涉及到变量读取等操作, 静态绑定失效
        cout << "f3() called !" << endl;
    };
};

using FUNC = void (*)();

void t0() {
    printf("%p\n", &A::x);
    printf("%p\n", &A::y);
    printf("%p\n", &A::f);
    printf("%p\n", &A::f1);
    printf("%p\n", &A::f2);
    printf("%p\n", &A::f3); // private 函数不可以取成员函数指针
    // 0x8
    // 0xc

    // 0x0
    // 0x8
    // 0x10
    // 0x104137890
    // 说明第一个地址是虚指针
    //
    // 普通函数是静态绑定
    // A *pa = NULL;
    // // pa->f1(); // crush
    // pa->f3(); // ok
}

void t1() {
    // 64-bit env
    A a;
    cout << hex;
    cout << "address of a : " << &a << endl;
    // cout << "address of vtbl : " << *(int *)(&a) << endl;
    cout << "address of vtbl : " << *(long *)(&a) << endl;
    // &a得到对象a的首地址，强制转换为(int*)
    // 意为将从&a开始的4个字节看作一个整体 而&a就是这个4字节整体的首地址
    // 再通过“*”对这个整体进行解引用 最终得到由这4个字节数据组成的地址
    // 也就是虚表的地址。
    long pvtbl = *(long *)(&a); // 其实相当于把地址(指针变量)强制类型转换为long
                                // 类型的值, 这个值其实就是虚表的首地址
    // 虚表的地址, 其实也就是一个数组的首地址
    long pf = *(long *)pvtbl;
    FUNC f = (FUNC)pf;
    f();

    long pf1 = *(long *)(pvtbl + 1 * sizeof(long));
    long pf2 = *(long *)(pvtbl + 2 * sizeof(long));
    FUNC f1 = (FUNC)pf1; // 转为函数指针
    FUNC f2 = (FUNC)pf2;
    f1();
    f2();
}

void t2() {
    A a;
    long pvtbl = *((long *)&a);
    auto pf1 = *((long *)pvtbl + 1);
    auto pf2 = *((long *)pvtbl + 2);
    auto f1 = (FUNC)pf1; // 转为函数指针
    auto f2 = (FUNC)pf2;
    f1();
    f2();
}

int main(int argc, char *argv[]) {
    t0();
    // t1();
    // t2();
    return 0;
}
