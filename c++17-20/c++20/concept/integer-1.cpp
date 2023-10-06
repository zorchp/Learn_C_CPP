#include <iostream>
#include <concepts>

// template <typename T>
// concept Foo = 1; // Atomic constraint must be of type 'bool' (found 'int')
template <typename T>
concept is_int = std::is_integral_v<T>;

void t1() {
    static_assert(std::floating_point<float>);
    // static_assert(is_int<float>);
    static_assert(!std::floating_point<int>);
}
