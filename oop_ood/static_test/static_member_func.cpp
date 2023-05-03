#include <iostream>

using namespace std;

/*
静态成员函数:
只能访问静态成员变量
所有对象共享一个函数
*/

class P {
public:
    P(){};

    ~P(){};

    static void func() {
        ma = 100;
        cout << "调用static func " << endl;
    }

    static void f2() { cout << "f2()\n"; }

    static int ma;
};

int P::ma = 10;

void t1() {
    cout << P::ma << endl; // 10
    // 类的实例化
    // 两种访问方式
    P p;
    // 通过对象访问
    p.func();
    // 通过类名进行访问
    P::func();
    cout << P::ma << endl; // 100
}

void t2() {
    auto ptr1 = P::func;
    auto ptr2 = &P::func;
    auto fp = &P::f2;
    ptr1();
    ptr2();
    cout << hex << ptr1 << endl;
    cout << ptr2 << endl;
    cout << fp << endl;
    cout << &P::ma << endl;
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}