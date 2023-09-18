#include <cassert>
#include <cstdio>
#include <iostream>
using namespace std;

#if __WORDSIZE == 64
using TYPE = unsigned long long;
#else
using TYPE = int;
#endif

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

void t00() {
    printf("%p\n", &A::f);
    printf("%p\n", &A::f1);
    printf("%p\n", &A::f2);
    printf("%p\n", &A::f3); // private 函数不可以取成员函数指针
    // 0x0
    // 0x8
    // 0x10
    // 0x1005c4020
    // why cout is 1
    cout << typeid(&A::x).name() << endl;  // M1Ai, int A::*
    cout << typeid(&A::f).name() << endl;  // M1AFvvE, void (A::*)()
    cout << typeid(&A::f1).name() << endl; // M1AFvvE, void (A::*)()
    // cout << &A::f << endl;  // 1
    // cout << &A::f1 << endl; // 1
    // cout << &A::f2 << endl; // 1
    // cout << &A::f3 << endl; // 1
}

void t0() {
    // 成员指针
    printf("%p\n", &A::x);
    printf("%p\n", &A::y);

    printf("%p\n", &A::f);
    printf("%p\n", &A::f1);
    printf("%p\n", &A::f2);
    printf("%p\n", &A::f3); // private 函数不可以取成员函数指针
    // 0x8
    // 0xc

    // 0x0, 即虚表指针位置, class 的头
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

void t10() { // 复习: 二级指针间接寻址过程
    int arr[3]{18, 22, 43};
    cout << typeid(arr).name() << endl;  // A3_i, int [3]
    cout << typeid(&arr).name() << endl; // PA3_i, int (*) [3]
    // arr 其实就是首地址, 值相同但是意义不同
    int *p = (int *)arr; // lost size info
    cout << *(p + 1) << endl;
    cout << *(p + 2) << endl;
    cout << *(arr + 1) << endl;
    cout << *(arr + 2) << endl;
    int **pp = &p;
    assert(p == arr);
    printf("arr=%p\n", arr);
    printf("p=%p\n", p);
    printf("pp=%p\n", pp);
    cout << typeid(pp).name() << endl; // PPi, int**
    // 此时 pp 是二级指针, 指向数组 arr 的首地址
    // 想解出来 arr 的各个元素, 就要先通过 pp 找到 arr 的首地址p,
    // 需要进行以下操作:
    // 1. 通过二级指针找到数组的原始地址, 这里在 64 位机器下使用 ull
    // 类型作为指针大小执行转换
    TYPE parr = *(TYPE *)pp;
    // parr 是 ull 类型的值, 值就是 p 的地址, 也就是数组头的地址
    int val1 = *(int *)parr; // 这里将数组头表示为数组内元素的指针,
                             // 然后解引用获取到元素的值
    int val2 = *((int *)parr + 1);
    int val3 = *((int *)parr + 2);
    cout << val1 << endl;
    cout << val2 << endl;
    cout << val3 << endl;
    // 22
    // 43
    // 22
    // 43
    // arr=0x16ce72a18
    // p=0x16ce72a18
    // pp=0x16ce72a10
    // PPi
    // 18
    // 22
    // 43
}

void t1() {
    // 64-bit env
    A a;
    cout << hex;
    cout << "address of a : " << &a << endl;
    cout << "address of vtbl : " << *(TYPE *)(&a) << endl;
    // &a得到对象a的首地址，强制转换为(TYPE*)
    // 意为将从&a开始的sizeof(TYPE)个字节看作一个整体
    // 而&a就是这个sizeof(TYPE)字节整体的首地址 再解引用,
    // 最终得到由这sizeof(TYPE)个字节数据组成的地址 也就是虚表的地址。
    TYPE vptr = *(TYPE *)(&a); // 其实相当于把地址(指针变量)强制类型转换为TYPE
                               // 类型的值, 这个值其实就是虚指针的值(指针变量)
    // 下面的转换指的是将 vptr 这个变量存储的地址信息变成数组指针,
    // 然后解引用得到第一个元素(即 TYPE 类型的指针),
    // 后续将其转换为函数指针进行调用
    cout << "vptr=" << vptr << endl;
    TYPE pf = *(TYPE *)vptr;
    // 这一步转换是必要的, 将 vptr 指向的数组的首地址解引用出来
    cout << "pf=" << pf << endl;
    // vptr=1028701d8
    // pf=102868b4c
    FUNC f = (FUNC)pf;
    f();

    TYPE pf1 = *(TYPE *)(vptr + 1 * sizeof(TYPE));
    TYPE pf2 = *(TYPE *)(vptr + 2 * sizeof(TYPE));
    FUNC f1 = (FUNC)pf1; // 转为函数指针
    FUNC f2 = (FUNC)pf2;
    f1();
    f2();
}

void t11() { // for heap memory
    // 64-bit env
    auto pa = new A;
    cout << hex;
    cout << "address of a : " << pa << endl;
    // cout << "address of vtbl : " << *(int *)(&a) << endl;
    cout << "address of vtbl : " << *(TYPE *)pa << endl;
    // &a得到对象a的首地址，强制转换为(int*)
    // 意为将从&a开始的4个字节看作一个整体
    // 而&a就是这个4字节整体的首地址
    // 再通过“*”对这个整体进行解引用
    // 最终得到由这4个字节数据组成的地址
    // 也就是虚表的地址。
    TYPE vptr = *(TYPE *)(pa); // 其实相当于把地址(指针变量)强制类型转换为TYPE
                               // 类型的值, 这个值其实就是虚表的首地址
    // 虚表的地址, 其实也就是一个数组的首地址
    TYPE pf = *(TYPE *)vptr;
    FUNC f = (FUNC)pf;
    f();

    TYPE pf1 = *(TYPE *)(vptr + 1 * sizeof(TYPE));
    TYPE pf2 = *(TYPE *)(vptr + 2 * sizeof(TYPE));
    FUNC f1 = (FUNC)pf1; // 转为函数指针
    FUNC f2 = (FUNC)pf2;
    f1();
    f2();
}
FUNC getvfunc(A *pa, int pos = 0) { return *((FUNC *)(*(TYPE *)pa) + pos); }

void t2() {
    A a;
    TYPE vptr = *(TYPE *)&a;
    auto pf1 = *((TYPE *)vptr + 1);
    auto pf2 = *((TYPE *)vptr + 2);
    auto f1 = (FUNC)pf1; // 转为函数指针
    auto f2 = (FUNC)pf2;
    f1();
    f2();
    // 可以合成一步:
    FUNC ff = *(FUNC *)(*(TYPE *)&a);
    ff();
    // 更进一步
    (*(FUNC *)(*(TYPE *)&a))();
    (*((FUNC *)(*(TYPE *)&a) + 1))();
    (*((FUNC *)(*(TYPE *)&a) + 2))();
    getvfunc(&a, 0)();
    getvfunc(&a, 1)();
    getvfunc(&a, 2)();
}

void t21() {
    auto pa = new A;
    TYPE vptr = *((TYPE *)pa);
    auto pf1 = *((TYPE *)vptr + 1);
    auto pf2 = *((TYPE *)vptr + 2);
    auto f1 = (FUNC)pf1; // 转为函数指针
    auto f2 = (FUNC)pf2;
    f1();
    f2();
    // f1() called !
    // f2() called !
}

void t3() {
    A a1, a2;
    TYPE vptr1 = *(TYPE *)&a1;
    auto pf1 = *((TYPE *)vptr1 + 1);
    auto f1 = (FUNC)pf1;
    f1();
    TYPE vptr2 = *(TYPE *)&a2;
    auto pf2 = *((TYPE *)vptr2 + 1);
    auto f2 = (FUNC)pf2;
    f2();
    // 同一个类的不同对象,
    // 由于编译期不知道具体要调用的函数(虚函数),
    // 所以只在运行期查虚函数表,
    // 此表是类拥有的(实际是在内存的 rodata 段),
    // 所以一个类的多个对象, 其虚函数表的地址(数组首地址)都是相同的,
    // 虚函数地址(函数指针)也相同

    // 虚函数表地址
    assert(vptr1 == vptr2);
    printf("%#lx\n", vptr1);
    printf("%#lx\n", vptr2);
    // 函数指针(TYPE 形式)
    assert(pf1 == pf2);
    printf("%#lx\n", pf1);
    printf("%#lx\n", pf2);
    // 函数指针(函数指针形式)
    assert(f1 == f2);
    printf("%#lx\n", f1);
    printf("%#lx\n", f2);
    // 函数指针的地址, 二级指针, 此时不相同了
    // assert(&f1 == &f2);
    printf("%#lx\n", &f1);
    printf("%#lx\n", &f2);
    FUNC *pp = &f1;
    (*pp)();
    // *(FUNC(*) & f1)();
    // *((FUNC *)&f2)();
}

int main(int argc, char *argv[]) {
    t00();
    // t0();
    // t10(); // 复习指针
    // t1();
    // t11();
    // t2();
    // t21();
    // t3();
    return 0;
}
