#include <iostream>
#include <format>
#include <cxxabi.h>


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
using namespace std;

void t1() {
    // 默认的浮点数字面量的类型为double
    // 加上 f 后缀之后是 float
    auto x = 1.5;
    auto y = 1.5f;
    print_type(x);
    print_type(y);
    // x : d => double
    // y : f => float
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
