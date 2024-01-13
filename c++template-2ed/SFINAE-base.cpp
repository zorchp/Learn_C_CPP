#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

template <typename T, unsigned N>
std::size_t len(T (&)[N]) { // N 个 T 类型元素的数组
    return N;
}

template <typename T>
typename T::size_type len(T const& t) {
    return t.size();
}

std::size_t len(...) { return 0; }

int main() {
    int a[10];
    std::cout << len(a) << std::endl;                    // 10
    std::cout << len("tmp") << std::endl;                // 4
    std::cout << len(std::vector<int>(10)) << std::endl; // 10
    int* p;
    std::cout << len(p) << std::endl; // match by ...
    std::allocator<int> x;
    std::cout << len(x) << std::endl; // match size_type.. but error


    return 0;
}
