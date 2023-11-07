#include <iostream>

int main(int argc, char *argv[]) {
    int a3[0][6];
    std::cout << sizeof(a3) << std::endl; // 0
    int a4[1];
    std::cout << sizeof(a4) << std::endl; // 4
    int a2[0] = {};
    std::cout << sizeof(a2) << std::endl; // 0
    int a1[] = {};
    std::cout << sizeof(a1) << std::endl; // 0
    return 0;
}
