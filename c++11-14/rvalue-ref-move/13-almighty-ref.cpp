#include <vector>
#include <iostream>
using namespace std;

void foo(int &&i) {} // i为右值引用

template <class T>
void bar(T &&t) {} // t为万能引用

int get_val() { return 5; }
int &&x = get_val();  // x为右值引用
auto &&y = get_val(); // y为万能引用

/*函数foo的形参i和变量x是右值引用，而函数模板的形参t和变量y则是万能引用。
 * 我们知道右值引用只能绑定一个右值，但是万能引用既可以绑定左值也可以绑定右值，
 * 甚至const和volatile的值都可以绑定*/

void t1() {
    int i = 42;
    const int j = 11;
    bar(i);
    bar(j);
    bar(get_val());

    auto &&x = i;
    auto &&y = j;
    auto &&z = get_val();
}
// 万能引用之引用折叠的推导规则:
/*
只要有左值引用参与进来，最后推导的结果就是一个左值引用。
只有实际类型是一个非引用类型或者右值引用类型时，最后推导出来的才是一个右值引用。
*/

template <class T>
// void foo(std::vector<T> &&t) {}
void foo(T &&t) {}
// void foo(auto &&t) {}//c++20

void t2() {
    std::vector<int> v{ 1,2,3 };
    foo(v);    // 如果不使用auto 或者模版, 导致编译错误
    /*因为foo的形参t并不是一个万能引用，而是一个右值引用。
    因为foo的形参类型是std::vector<T>&&而不是T&&，
    所以编译器无法将其看作一个万能引用处理。*/
}


int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}