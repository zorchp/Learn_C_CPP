#include <bits/stdc++.h>
using namespace std;

// 指针变量的大小
#if __WORDSIZE == 64
using TYPE = unsigned long long;
#else
using TYPE = int;
#endif

// #define VIRTUAL_INHERIT

class B1 {
public:
    virtual void f1() { cout << "B1::f1()\n"; }
    virtual void fb1() { cout << "B1::fb1()\n"; }
    void ff() { cout << "B1::ff()\n"; }
};

class B2 : public
#ifdef VIRTUAL_INHERIT
           virtual
#endif
           B1 {
public:
    virtual void f1() override { cout << "B2::f1()\n"; }
    virtual void fb2() { cout << "B2::fb2()\n"; }
};

class B3 : public
#ifdef VIRTUAL_INHERIT
           virtual
#endif
           B1 {
public:
    virtual void f1() override { cout << "B3::f1()\n"; }
};

class C : public B2, public B3 {
public:
    void f1() override final { cout << "C::f1()\n"; }
    virtual void f2() { cout << "C::f2()\n"; }
};

using FUNC = void (*)();

/* 仅针对类 C, 可视情况修改 */
FUNC getvfunc(C *pa, int vptr_offset = 0, int vtbl_offset = 0) {
    TYPE vptr = *(reinterpret_cast<TYPE *>(pa) + vptr_offset);
    FUNC vfunc = *(reinterpret_cast<FUNC *>(vptr) + vtbl_offset);
    return vfunc;
}

FUNC getvfunc(B2 *pa, int vptr_offset = 0, int vtbl_offset = 0) {
    TYPE vptr = *(reinterpret_cast<TYPE *>(pa) + vptr_offset);
    FUNC vfunc = *(reinterpret_cast<FUNC *>(vptr) + vtbl_offset);
    return vfunc;
}

FUNC getvfunc(B3 *pa, int vptr_offset = 0, int vtbl_offset = 0) {
    TYPE vptr = *(reinterpret_cast<TYPE *>(pa) + vptr_offset);
    FUNC vfunc = *(reinterpret_cast<FUNC *>(vptr) + vtbl_offset);
    return vfunc;
}

void t1() {
    cout << sizeof(B1) << endl; // 8
    cout << sizeof(B2) << endl; // 8
    cout << sizeof(B3) << endl; // 8
    cout << sizeof(C) << endl;  // 16
}

void t2() {
    // 先分析 中间基类
    auto pb2 = new B2;
    auto pb2f = getvfunc(pb2, 0, 1);
    auto pb3 = new B3;
    auto pb3f = getvfunc(pb3, 0, 1);
    pb2f();
    pb3f();
    printf("%p\n", pb2f);
    printf("%p\n", pb3f);
    // B1::fb1()
    // B1::fb1()
    // 0x1049bf3b8
    // 0x1049bf3b8
}

void t3() {
    auto pb2 = new B2;
    getvfunc(pb2, 0, 0)();
    getvfunc(pb2, 0, 1)();
    getvfunc(pb2, 0, 2)();
    // B2::f1() 重写的
    // B1::fb1() 基类的
    // B2::fb2() 自己的

    cout << string(50, '=') << endl;

    auto pb3 = new B3;
    getvfunc(pb3, 0, 0)();
    getvfunc(pb3, 0, 1)();
    // B3::f1() 重写的
    // B1::fb1() 基类的
    auto pb2fb1 = getvfunc(pb2, 0, 1);
    auto pb3fb1 = getvfunc(pb3, 0, 1);
    // 一样的
    printf("%p\n", pb2fb1);
    printf("%p\n", pb3fb1);
    assert(pb2fb1 == pb3fb1);
}

void t4() {
    // 针对派生类 C
    auto pc = new C;
    // 第一张虚表, 继承自 B2, 并且还有自己的虚函数
    getvfunc(pc, 0, 0)();
    getvfunc(pc, 0, 1)();
    getvfunc(pc, 0, 2)();
    getvfunc(pc, 0, 3)();
    // C::f1() 重写自B2
    // B1::fb1() B2 包含的 B1 的, 虚继承情形下仅有一份间接基类 B1 的虚函数
    // B2::fb2() B2 的
    // C::f2() 自己的
    cout << string(50, '=') << endl;
    // 第二张虚表, 继承自 B3
    getvfunc(pc, 1, 0)();
#ifndef VIRTUAL_INHERIT
    getvfunc(pc, 1, 1)();
#endif
    // C::f1() 重写自B3
    // 仅未执行虚继承时候才会有 此条目
    // B1::fb1() B3 中包含的 B1 的虚函数, 如果不进行虚继承, 类 C
    // 虚表中将会有两份
}


int main(int argc, char *argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}
