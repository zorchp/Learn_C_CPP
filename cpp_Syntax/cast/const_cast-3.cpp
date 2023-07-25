#include <cstdio>
#include <iostream>


using namespace std;

void t1() {
    const char* p = "abc";
    auto q = const_cast<char*>(p);
    // q[0] = ' ';
    cout << q;
}

void t2() {
    int a = 10;
    const int b = 20;
    printf("%p, %p\n", &a, &b);
    // clang,64bit
    // 0x16b27e9e0, 0x16b27e9f0
    int* p = &a + 0x10;
    *p = 30;
    cout << a << endl;
    cout << b << endl;
    cout << *p << endl;
    // 编译器行为, 通过指针改常量, 常量最后的结果还是原来的值
}

int main(int argc, char* argv[]) {
    // t1();
    t2();
    return 0;
}
