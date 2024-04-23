#include <iostream>

namespace version1 {

template <typename T>
T accum(T const *beg, T const *end) {
    T total{}; // assume this actually creates a zero value
    while (beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
}
} // namespace version1

namespace type_traits {
template <typename T>
struct AccumulationTraits;

template <>
struct AccumulationTraits<char> {
    using AccT = int;
};

template <>
struct AccumulationTraits<short> {
    using AccT = int;
};

template <>
struct AccumulationTraits<int> {
    using AccT = long;
};

template <>
struct AccumulationTraits<unsigned int> {
    using AccT = unsigned long;
};

template <>
struct AccumulationTraits<float> {
    using AccT = double;
};

template <typename T>
auto accum(T const *beg, T const *end) {
    using AccT = typename AccumulationTraits<T>::AccT;
    AccT total{}; // assume this actually creates a zero value
    while (beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
}

} // namespace type_traits

int main(int argc, char *argv[]) {
    // using namespace version1;
    using namespace type_traits;
    int num[] = {1, 2, 3, 4, 5};
    std::cout << "the average of the integer values is "
              << accum(num, num + 5) / 5 << '\n';
    char name[] = "templates";
    int length = sizeof(name) - 1;
    std::cout << "the average value of the characters in \"" << name << "\" is "
              << accum(name, name + length) / length << '\n';
    /*the average of the integer values is 3
the average value of the characters in "templates" is -5 */

    // after using type traits
    // the average of the integer values is 3
    // the average value of the characters in "templates" is 108

    return 0;
}
