#include <cxxabi.h>
#include <iostream>
#include <format>


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

class B {};
class D : public B {};

int main(int argc, char *argv[]) {
    B *pb = new D;
    print_type(*pb);
    //*pb : 1B => B

    return 0;
}
