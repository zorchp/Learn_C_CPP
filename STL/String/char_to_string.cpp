#include <string>
#include <vector>
#include <iostream>
#include <format>
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

void t1() {
    [[maybe_unused]] char a = 'a';
    // string s(a); // can not converse char to string
    string s("a");
    cout << s << endl;
}

void t2() {
    [[maybe_unused]] const char* cc = "123dbc";
    // for (auto c : cc) cout << c << " "; // error
    cout << endl;
}

void t3() {
    auto s = "abcdef";
    print_type(s); // const char*
    auto ss = "abcdef"s;
    print_type(ss);
}

void t4() {
    auto s = "abcdef"s;
    auto cs = s.data();
    print_type(cs);
    auto cs1 = s.c_str();
    print_type(cs1);
    // cs : Pc => char*
    // cs1 : PKc => char const*
    cs[1] = 'v';
    cout << cs << endl;
    // cs1[1] = 'v'; // read-only
}


int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}
