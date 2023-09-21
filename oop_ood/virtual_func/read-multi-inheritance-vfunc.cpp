#include <bits/stdc++.h>
using namespace std;

// 指针变量的大小
#if __WORDSIZE == 64
using TYPE = unsigned long long;
#else
using TYPE = int;
#endif

class B1 {
public:
    virtual void f1() { cout << "B1::f1()\n"; }
    virtual void fb1() { cout << "B1::fb1()\n"; }
};

class B2 {
public:
    virtual void f1() { cout << "B2::f1()\n"; }
};

class B3 {
public:
    virtual void f1() { cout << "B3::f1()\n"; }
};

class C : public B1, public B2, public B3 {
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
    // C-style
    // return *((FUNC *)(*((TYPE *)pa + vptr_offset)) + vtbl_offset);
}

void t1() {
    // 三个基类, 每个基类都含有虚指针, 所以结果是 24,
    // 为什么自己的虚函数对应的虚指针没算在内??? 难道是进行了合并吗
    // 看下面代码, 确实合并了, 放在了第一张虚表后面
    cout << sizeof(B1) << endl; // 8
    cout << sizeof(B2) << endl; // 8
    cout << sizeof(B3) << endl; // 8
    cout << sizeof(C) << endl;  // 24
    C c;
    // getvfunc(&c, 0)();
    // printf("%p\n", &C::f1);     // 0x0
    // printf("%p\n", &C::B1::f1); // 0x0
}

void t2() {
    auto pc = new C;
    TYPE vptr1 = *(TYPE *)pc;
    FUNC f = *(FUNC *)vptr1;
    f();
    FUNC f0 = *((FUNC *)vptr1 + 1);
    f0();
    TYPE vptr2 = *((TYPE *)pc + 1);
    FUNC f1 = *(FUNC *)vptr2;
    f1();
    TYPE vptr3 = *((TYPE *)pc + 2);
    FUNC f2 = *(FUNC *)vptr3;
    f2();
    // FUNC f3 = *((FUNC *)vptr3 + 1);
    // f3();
}

void t3() {
    auto pc = new C;
    // 第一张虚表
    getvfunc(pc, 0, 0)();
    getvfunc(pc, 0, 1)();
    getvfunc(pc, 0, 2)();
    // 第二张虚表
    getvfunc(pc, 1, 0)();
    // 第三张虚表
    getvfunc(pc, 2, 0)();
    // C::f1()
    // B1::fb1()
    // C::f2()
    // C::f1()
    // C::f1()
}

int main(int argc, char *argv[]) {
    // t1();
    // t2();
    t3();

    return 0;
}
