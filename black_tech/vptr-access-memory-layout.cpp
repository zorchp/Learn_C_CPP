#include <iostream>
#include <typeinfo>
using namespace std;

typedef long long u64;
typedef void (*pFunc)();

// not a good way, using lambda instead
// #define GET_PTR(ptr) (*(u64*)(ptr))
auto GET_PTR = [](auto ptr) { return *(u64*)(ptr); };

class A {
public:
    virtual void a() { cout << "A a()" << endl; }
    virtual void b() { cout << "A b()" << endl; }
    virtual void c() { cout << "A c()" << endl; }
    int x{8}, y{10};
};

class B : public A {
public:
    int z{12};
    virtual void b() { cout << "B b()" << endl; }
};


class C {
public:
    virtual void d() { cout << "C d()" << endl; }
    virtual void e() { cout << "C e()" << endl; }
    virtual void f() { cout << "C f()" << endl; }
};


void t1() {
    A a;
    u64* p = (u64*)&a;
    u64* arr = (u64*)*p;

    pFunc fa = (pFunc)arr[0];
    pFunc fb = (pFunc)arr[1];
    pFunc fc = (pFunc)arr[2];
    fa();
    fb();
    fc();
    /*
    A a()
    A b()
    A c()
    */
}

void t2() {
    A a1, a2;
    u64* p = (u64*)&a1;
    cout << *p << endl;
    p = (u64*)&a2;
    cout << *p << endl;
    // 4305830448
    // 4305830448
}

void t3() {
    B b;
    u64* p = (u64*)&b;
    u64* arr = (u64*)*p;
    pFunc fa = (pFunc)arr[0];
    pFunc fb = (pFunc)arr[1];
    pFunc fc = (pFunc)arr[2];
    fa();
    fb();
    fc();
    // A a()
    // B b()
    // A c()
}

void t4() {
    A a;
    u64* pa = (u64*)&a;
    u64* arra = (u64*)*pa;
    B b;
    u64* pb = (u64*)&b;
    u64* arrb = (u64*)*pb;
    for (int i = 0; i < 3; i++) {
        cout << hex << arra[i] << " " << arrb[i] << endl;
    }
    // 1021852b0 1021852b0
    // 1021853f0 1021857c8
    // 102185530 102185530
}

void t51() {
    A* a1 = new A;
    A* a2 = new A;
    A* a3 = new B;
    B* b = new B;
    cout << hex << *(u64*)a1 << endl; // 102adc210
    cout << hex << *(u64*)a2 << endl; // 102adc210
    cout << hex << *(u64*)a3 << endl; // 104224238
    cout << hex << *(u64*)b << endl;  // 104224238
}

void t52() {
    A* a1 = new A;
    A* a2 = new A;
    A* a3 = new B;
    B* b = new B;

    // 找到 a3 的虚指针:
    u64 vptr = GET_PTR(a3);
    printf("虚表地址: %p\n", (void*)vptr);

    // cout << sizeof((pFunc)vptr) << endl; // 8
    for (int i{-2}; i < 6; ++i)
        printf("[%d] %p\n", i, (void*)GET_PTR(vptr + i * 8));

    printf("第一个虚函数地址: %p\n", (void*)GET_PTR(vptr));
    printf("第二个虚函数地址: %p\n", (void*)GET_PTR(vptr + 8));
    pFunc f = (pFunc)GET_PTR(vptr);
    f();
    pFunc g = (pFunc)GET_PTR(vptr + 8); // 64bit
    g();
    pFunc h = (pFunc)GET_PTR(vptr + 16);
    h();
    // 通过基类指针访问派生类才有的成员
    // a3->b(); //
    // 可以直接访问虚函数, 但是不能直接访问数据成员, 需要 dynamic_cast

    // 方法 1: 运行时类型识别
    cout << "z=" << dynamic_cast<B*>(a3)->z << endl;
    // 方法 2: 从内存模型出发, z 在 y 的下面,
    // 所以可以通过指针的操作来完成取值
    // (但是如果内存不一样大, 就会出问题)
    cout << "z=" << *(&(a3->y) + 1) << endl;
    // cout << a3->z << endl; // error
    cout << "x=" << *(&(a3->y) - 1) << endl;
    // 分别是 x, y, z
    cout << *(&(a3->y) - 1) << endl; // 8
    cout << *(&(a3->y)) << endl;     // 10
    cout << *(&(a3->y) + 1) << endl; // 12
    /*虚表地址: 0x1028b4258
    8
    [-2] 0x0
    [-1] 0x1028b4208
    [0] 0x1028ad328
    [1] 0x1028ad840
    [2] 0x1028ad5a8
    [3] 0x0
    [4] 0x1028b4298
    [5] 0x1028ade58
    第一个虚函数地址: 0x1028ad328
    第二个虚函数地址: 0x1028ad840
    A a()
    B b()
    A c()
    z=12
    z=12
    x=8*/
}

void t6() {
    // 移花接木
    A* a = new A;
    C* c = new C;
    *(u64*)a = *(u64*)c;
    // when use sanitizer: runtime error
    a->a();
    a->b();
    a->c();
    // C d()
    // C e()
    // C f()
}

void t53() {
    // 成员函数指针访问
    A* a1 = new A;
    A* a2 = new A;
    A* a3 = new B;
    B* b = new B;
    // void (B::*p)(void) = &B::b;
    auto p = &B::b;
    cout << typeid(p).name() << endl;
    // M1BFvvE 
    // c++filt -t M1BFvvE 
    // void (B::*)()
    (b->*p)();
    (dynamic_cast<B*>(a3)->*p)();
}

int main() {
    // t1();
    // t2();
    // t3();
    // t4();
    // t51();
    // t52();
    t53();
    // t6();
    return 0;
}
