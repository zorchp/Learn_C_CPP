#include <cstdio>
#include <iostream>
using namespace std;
void ConstTest1() {
    const int a = 1;
    int *p;
    p = const_cast<int *>(&a);
    // (*p)++;
    *p = 2;
    cout << a << endl;  // 1
    cout << *p << endl; // 2
    cout << a << endl;  // 1
    printf("%p, %p, %p\n", &a, p, &*p);
    // 通过指针操作改变了值, 但是输出时候还是会由编译器返回原来的值
}

void ConstTest2() {
    int i = 3;
    const int a = i;
    int &r = const_cast<int &>(a);
    r++;
    cout << i << endl; // 3
    cout << r << endl; // 4
    cout << a << endl; // 4
}
int main() {
    ConstTest1();
    // ConstTest2();
    return 0;
}
