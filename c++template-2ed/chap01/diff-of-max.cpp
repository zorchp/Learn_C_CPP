#include <iostream>

template <typename T>
T max(T a, T b) {
    return b < a ? a : b;
}

void t1() {
    // std::cout << max(1, 3) << std::endl; // 3
    float a = 10, b = NAN;
    std::cout << std::boolalpha << (a == b) << std::endl;
    std::cout << std::boolalpha << (a > b) << std::endl;
    std::cout << std::boolalpha << (a < b) << std::endl;
    std::cout << (b < a ? a : b) << std::endl; // NAN
    std::cout << (a < b ? b : a) << std::endl; // 10
    // false
    // false
    // false
    // nan
    // 10
}

int main(int argc, char *argv[]) {
    t1();


    return 0;
}
