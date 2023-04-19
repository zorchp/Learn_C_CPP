#include <iostream>

using namespace std;


/*
const修饰指针: 常量指针  -> 指针指向的值不可以改,指针指向可以改
const修饰常量: 指针常量 -> 指针指向不可以改, 指针指向的值可以改
const指针和常量均修饰  -> 均不能改
*/

void test1() {
    int a = 10;
    int b = 10;
    // 这个是常量指针: 必须初始化, 并且初始化后值不能改变
    const int *p1 = &a;
    // *p1=100;  -> 值不可以改
    p1 = &b; // 指向可以改

    // 这个是指针常量
    int *const p2 = &a; // 必须初始化, 初始化后指向不能改变(是引用的本质)
    // p2 = &b;  // 指向不可以改
    *p2 = 20; // ->值可以改

    // 这个是const两者都修饰
    const int *const p3 = &a;
    // p3=&b;
    // *p3 = 20;
    cout << *p3 << endl;
    string s(30, '-');
    cout << s << endl;
}

void test2() {
    // 顶层 const: 指针本身是常量;
    // 底层 const: 指针所指对象为常量;
    int i = 0, j = 1;
    int *const pi = &i;  // 引用,指针常量
    const int ci  = 42;  // 任意对象是常量
    const int *p2 = &ci; // 常量指针, 指向可以修改, 值不能改
    // pi=&j; // top-level const don't allow to modify pi;
    // ci=j; // top-level const
    p2 = &j; // low-level const
    // p2 = 10;

    const int *const p3 = p2; //第一个const 底层const, 第二个const 顶层const
    // p3=&i;
    const int &r = ci; //声明 `引用`的const 都是底层const
}

void test3() { int null = 0, *p = &null; }

int main(int argc, char const *argv[]) {
    // test1();
    // test2();
    test3();

    return 0;
}