#include <cstdio>
#include <iostream>

using namespace std;

/*
函数模板

*/
template <typename T>
void func(T &a, T &b) {
    T t = a;
    a = b;
    b = t;
}

void test() {
    int a = 1, b = 2;
    cout << a << b << endl;
    // 自动类型推导
    func(a, b);
    // 显式指定类型
    func<int>(a, b);
    cout << a << b << endl;
}

template <typename T>
void f(T) {
    puts("1");
}

class P {
public:
    typedef int foo;
};

template <typename T>
void f(typename T::foo) {
    puts("1");
}

void t1() {
    f<int>(12);
    f<P>(12);
}

int main(int argc, char const *argv[]) {
    // test();
    t1();
    return 0;
}
