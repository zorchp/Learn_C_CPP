#pragma once
#include <iostream>
#include <cxxabi.h>
// ref from c++20 guide
template <typename, typename...>
struct [[deprecated]] print_type_static {};

template <typename... Ts>
void print_type_dynamic() {
#ifdef _WIN32
    std::cout << __FUNCSIG__ << std::endl;
#else
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
}


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
