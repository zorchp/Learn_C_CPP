#include <bits/stdc++.h>
using namespace std;

// 指针变量的大小
#if __WORDSIZE == 64
using TYPE = unsigned long long;
#else
using TYPE = int;
#endif

class B {
public:
    virtual void f1() { cout << "B::f1()\n"; }
    virtual void f2() { cout << "B::f2()\n"; }
};

class C : public B {
public:
    void f1() override final { cout << "C::f1()\n"; }
    virtual void f3() { cout << "C::f3()\n"; }
};

using FUNC = void (*)();
/* 仅针对类 C, 可视情况修改 */
FUNC getvfunc(C *pa, int vptr_offset = 0, int vtbl_offset = 0) {
    TYPE vptr = *(reinterpret_cast<TYPE *>(pa) + vptr_offset);
    FUNC vfunc = *(reinterpret_cast<FUNC *>(vptr) + vtbl_offset);
    return vfunc;
}

void t1() {
    // 均只含有个虚指针(即一张虚表)
    cout << sizeof(B) << endl; // 8
    cout << sizeof(C) << endl; // 8
}

void t2() {
    auto pc = new C;
    getvfunc(pc, 0, 0)(); // C 重写的 f1
    getvfunc(pc, 0, 1)(); // 父类 B 的 f2
    getvfunc(pc, 0, 2)(); // C 自己的 f3
    // C::f1()
    // B::f2()
    // C::f3()
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
