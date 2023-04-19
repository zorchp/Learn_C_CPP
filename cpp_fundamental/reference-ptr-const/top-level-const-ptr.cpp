#include <iostream>
/*顶层const:指针本身是常量
底层const:指针所指向的对象是常量*/
using namespace std;

int main(int argc, char const *argv[]) {
    int i = 0;
    int *const p1 = &i; //指针常量,top-const,指针本身是常量
    // 顶层const可以表示任意对象是常量
    const int ci = 42;        // top-const
    const int *p2 = &ci;      // low-const
    const int *const p3 = p2; // low,top
    const int &r = ci; // low-const,用于声明引用的const都是底层const
    // copy操作, 顶层const对操作无影响
    i = ci;
    p2 = p3; //指向的对象类型相同
    // copy对底层会产生影响
    // int *p = p3; // error:p3包含底层const定义,p没有
    p2=p3;//都是底层const
    p2=&i;//int* -> const int*
    // int&r1=ci;//error:普通int&不能绑定到const int上
    int i1;
    const int &r2=i1;
    return 0;
}