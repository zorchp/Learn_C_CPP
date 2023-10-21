#include <bits/stdc++.h>
#include <cxxabi.h>
using namespace std;

#if __cplusplus < 202002
#define print_type(x)                                                    \
    std::cout << #x << typeid(x).name() << " => "                        \
              << abi::__cxa_demangle(typeid(x).name(), NULL, NULL, NULL) \
              << std::endl
#else
#define print_type(x)                            \
    std::cout << std::format(                    \
        "{} : {} => {}\n", #x, typeid(x).name(), \
        abi::__cxa_demangle(typeid(x).name(), NULL, NULL, NULL))
#endif


char (*(*TYPE1())[])();
// char (*((*TYPE2)())[])(); // Function cannot return array type 'char (*[])()'

void t1() {
    // typedef char (*(*TYPE1())[])();
    // TYPE1 是函数, 参数列表为void, 返回值是一个指针, 指针指向数组,
    // 数组元素是函数指针, 函数指针指向的函数的返回值为 char, 参数列表为空
    print_type(TYPE1); // TYPE1 : FPA_PFcvEvE => char (* (*()) [])()
    // TYPE1();
}

void t2() {
    typedef char(*(*TYPE2[3])())[5];
    // TYPE2 是一个3个元素的数组 数组里的元素是函数指针
    //  这些函数指针所指向的函数的返回值也是指针
    //  该指针指向一个有5个char类型元素的数组。
    print_type(TYPE2); // TYPE2 : A3_PFPA5_cvE => char (*(* [3])()) [5]
}

int f1() { return 1; }
void t3() {
    typedef int (*(*TYPE3)[])();
    // 指向数组的指针, 数组中元素为返回值为 int 类型的函数
    int (*arr[3])();
    arr[0] = f1;
    TYPE3 parr = &arr;
    print_type(parr);     // parr : PA_PFivE => int (* (*) [])()
    cout << (*parr)[0](); // 1
}

int main(int argc, char* argv[]) {
    // t1();
    t2();
    // t3();
    return 0;
}
