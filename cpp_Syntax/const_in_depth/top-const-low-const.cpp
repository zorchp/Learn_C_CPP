#include <bits/stdc++.h>
using namespace std;
// top-level-const : ptr is constant
// low-level-const : ptr to val is constant

void t1() {
    int i = 0;
    int *const p1 = &i;  // top-level-const, 指针常量
    const int ci = 42;   // top-level-const, 整型常量
    const int *p2 = &ci; // low-level-const, 常量指针

    const int *const p3 = p2; // 左边底层右边顶层
    const int &r = ci; // 引用情形修改的也是对象本身, 是底层 const

    i = ci;
    p2 = p3; // p3 顶层 const 不会影响 Copy

    // int *p = p3; // 底层 const 阻止不同类型的 Copy
    p2 = &i; // 非常量向常量存在隐式类型转换

    // int &rr = ci; // 此时底层 const(引用)生效, 类型不同不能绑定引用
    const int &r2 = i; // 非常量到常量
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
