#include <iostream>
using namespace std;

void test1() {
    int n = 1, *p = &n;
    // void* 是一种特殊的指针, 可用于存放任意类型对象的地址
    // 但是无法进行解引用操作, 因为不知道存放地址指向变量的类型是什么
    // int** a=&p; // 正确, 指针的指针
    void* a = &p;
    cout << a << endl;
    // cout<<*a<<endl; // 错误,不支持解引用
}

void test2() {
    int arr[] = {1, 2, 3}, *p = arr;
    void* pv = arr;
    // cout<<*arr<<endl;
    // cout<<*pv<<endl; // 错误, void*指针不支持解引用

    // cout<<*pv<<endl;
}

void test3() {
    int i   = 42;
    void* p = &i;
    // long *lp = &i; // 非法, 类型不一致
}


int main(int argc, char const* argv[]) {
    // test1();
    // test2();
    test3();
    return 0;
}
