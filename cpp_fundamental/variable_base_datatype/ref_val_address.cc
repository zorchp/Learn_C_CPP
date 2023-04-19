#include <iostream>

using namespace std;

// 交换变量:值传递方法
void swap_val(int a, int b) {
    int t = a;
    a     = b;
    b     = t;
    cout << a << endl;
    cout << b << endl;
}

// 交换变量: 引用传递
// 引用的本质是**指针常量**!!
void swap_ref(int &a, int &b) {
    int t = a;
    a     = b;
    b     = t;
    cout << a << endl;
    cout << b << endl;
}

// 交换变量:地址传递
void swap_ads(int *a, int *b) {
    int t = *a;
    *a    = *b;
    *b    = t;
    cout << *a << endl;
    cout << *b << endl;
}

int main() {
    // 值传递,只改变形参, 不会改变实参
    int a = 10;
    int b = 20;
    // swap_val(a, b);
    // cout<<a<<endl;
    // cout<<b<<endl;
    // 引用传递(recommend), 既改变形参, 又改变实参, 使用变量的引用进行值的修改
    // swap_ref(a, b);
    // cout<<a<<endl;
    // cout<<b<<endl;
    // 地址传递, 改变的是指针指向的变量地址, 也会改变实参和形参
    swap_ads(&a, &b);
    cout << a << endl;
    cout << b << endl;
    return 0;
}