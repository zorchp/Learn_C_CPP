#include <cstddef>
#include <iostream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, std::byte b) {
    return os << std::bitset<32>(std::to_integer<int>(b));
}

int main(int argc, char *argv[]) {
    std::byte b{42};
    std::cout << b << std::endl;
    b <<= 1;
    b >>= 1;
    std::cout << b << std::endl;
    return 0;
}
