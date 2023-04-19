#include <iostream>
#include <complex>
using namespace std;
/*
右值引用, 用于解决不必要的拷贝和赋值操作
左值: 变量, 可左可右
右值: 不可以放在左边, 只能在右边, 临时对象是右值

*/

void t1() {
    int a = 4, b = 3;
    a = b;
    b = a;
    a = a + b;
    // a + b = 42;//error
}

void t2() {
    string s1("Hello "), s2("World");
    s1 + s2 = s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    string() = "peter"; // 可以对临时对象赋值
}

void t3() {
    complex<int> c1(1, 2), c2(3, 4);
    c1 + c2 = c2;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    complex<int>() = c1; // 可以对临时对象赋值
}


int foo() { return 1; }
void t4() {
    int x = foo();
    // int *p = &foo();//error: cannot take the address of an rvalue of type
    // 'int' foo() = 3;//error: expression is not assignable
}

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}
