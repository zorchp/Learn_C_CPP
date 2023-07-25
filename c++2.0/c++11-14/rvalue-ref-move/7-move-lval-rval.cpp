#include <iostream>
#include <vector>

using namespace std;

void t1() {
    int &&rr1 = 42;
    /* int &&rr2 = rr1; // error */
    int &&rr3 = std::move(rr1);
    cout << rr1 << std::endl; // 42
    cout << rr3 << std::endl; // 42
}

void t2() {
    int a = 10;
    int &&b = std::move(a);
    cout << &a << endl; // 10
    cout << &b << endl; // 10
}

void t3() {
    int &&c = std::move(10);
    cout << c << endl; // 10
}
void t4() {
    int *p = new int(42);
    int &&r = std::move(*p);
    cout << r << endl;
    r = 1;
    *p = 3; // 编译器不报错，也不会阻止修改源对象值，但不建议这么做
    cout << r << endl;
    cout << *p << endl;
}

void t5() {
    string s1("hi!"), s2;
    s2 = std::move(string("bye"));
    cout << s1 << " " << s2 << endl;
    cout << &s1 << " " << &s2 << endl;
    cout << typeid(s1).name() << endl;
    cout << typeid(s2).name() << endl;
    cout << endl;
    s2 = std::move(s1);
    // s1 = nullptr;
    cout << s1 << " " << s2 << endl;
    cout << &s1 << " " << &s2 << endl;
    cout << typeid(s1).name() << endl;
    cout << typeid(s2).name() << endl;
    /* hi! bye */
    /* 0x16d09ab80 0x16d09abc0 */
    /*  hi! */
    /* 0x16d09ab80 0x16d09abc0 */
}

int main(int argc, char const *argv[]) {
    // t1();
    /* t2(); */
    /* t3(); */
    /* t4(); */
    t5();
    return 0;
}
