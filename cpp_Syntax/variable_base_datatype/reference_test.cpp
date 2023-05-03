#include <iostream>
using namespace std;

int main(int argc, char const* argv[]) {
    int x  = 0;
    int* p = &x;
    int& r = x;

    int x2 = 5;
    // &r=x2; // 错误, 不能改变引用变量指向的对象。
    r = x2; // 正确, 本质上是利用引用r来改变它所指对象x的值
    cout << "x: " << x << endl;
    cout << "r: " << r << endl;
    // 下面的地址以及占用内存大小均相同, 是由reference保证的行为
    cout << "&x: " << &x << endl;
    cout << "&r: " << &r << endl;
    cout << "sizeof(x): " << sizeof(x) << endl;
    cout << "sizeof(r): " << sizeof(r) << endl;
    // 64位指针占8字
    cout << "sizeof(p): " << sizeof(p) << endl;
    cout << "*p: " << *p << endl;
    return 0;
}
