#include <cxxabi.h>
#include <format>
#include <iostream>
using namespace std;


#if __cplusplus < 202002
#define print_type(x)                                                    \
    std::cout << #x << typeid(x).name() << " => "                        \
              << abi::__cxa_demangle(typeid(x).name(), NULL, NULL, NULL) \
              << '\n'
#else
#define print_type(x)                            \
    std::cout << std::format(                    \
        "{} : {} => {}\n", #x, typeid(x).name(), \
        abi::__cxa_demangle(typeid(x).name(), NULL, NULL, NULL))
#endif

using FUNC [[maybe_unused]] = string (*)(int, char);

auto f = [](int x, char y) {
    string s;
    return s + to_string(x + y);
};

void t1() {
    //
    print_type(f);
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
