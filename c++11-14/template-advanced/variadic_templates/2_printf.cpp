#include <iostream>

using namespace std;

//使用varadic template重写printf()函数
void printf1(const char* s) {
    while (*s) {
        if (*s == '%' && *(++s) != '%')
            throw runtime_error("invalid format string: missing arguments");
        std::cout << *s++;
    }
}


template <typename T, typename... Args>
void printf1(const char* s, T value, Args... args) {
    while (*s) {
        if (*s == '%' && *(++s) != '%') {
            std::cout << value;
            printf1(
                ++s,
                args...); // call even when *s == 0 to detect extra arguments
            return;
        }
        std::cout << *s++;
    }
    throw logic_error("extra arguments provided to printf1");
}


int main(int argc, char const* argv[]) {
    // float pi = 3.14159265;
    int* pi = new int;
    printf("%d %f %s %p %%\n", 1, 2.3, "'f'", pi);
    printf1("%d %f %s %p %%\n", 1, 2.3, "'f'", pi);
    return 0;
}
