#include <iostream>
template <typename T>
struct AccumulationTraits;

template <>
struct AccumulationTraits<char> {
    using AccT = int;

    static AccT constexpr zero() { return 0; }
};

template <>
struct AccumulationTraits<short> {
    using AccT = int;

    static AccT constexpr zero() { return 0; }
};

template <>
struct AccumulationTraits<int> {
    using AccT = long;

    static AccT constexpr zero() { return 0; }
};

template <>
struct AccumulationTraits<float> {
    using AccT = double;

    static AccT constexpr zero() { return 0; }
};

template <>
struct AccumulationTraits<unsigned int> {
    using AccT = unsigned long;

    static AccT constexpr zero() { return 0; }
};

template <typename T>
auto accum(T const* beg, T const* end) {
    using AccT = typename AccumulationTraits<T>::AccT;
    AccT total = AccumulationTraits<T>::zero; // init total by trait value
    while (beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
}

// policy class

namespace version1 {

class SumPolicy {
public:
    template <typename T1, typename T2>
    static void accumulate(T1& total, T2 const& value) {
        total += value;
    }
};

class MulitPolicy {
public:
    template <typename T1, typename T2>
    static void accumulate(T1& total, T2 const& value) {
        total *= value;
    }
};

// calc
template <typename T, typename Policy = SumPolicy,
          typename Traits = AccumulationTraits<T>>
auto accum(T const* beg, T const* end) {
    using AccT = typename Traits::AccT;
    AccT total = Traits::zero();
    while (beg != end) {
        Policy::accumulate(total, *beg);
        ++beg;
    }
    return total;
}
} // namespace version1

namespace template_template_argument {
template <typename T1, typename T2>
class SumPolicy {
public:
    static void accumulate(T1& total, T2 const& value) { total += value; }
};

template <typename T1, typename T2>
class MulitPolicy {
public:
    static void accumulate(T1& total, T2 const& value) { total *= value; }
};

template <typename T, template <typename, typename> class Policy = SumPolicy,
          typename Traits = AccumulationTraits<T>>
auto accum(T const* beg, T const* end) {
    using AccT = typename Traits::AccT;
    AccT total = Traits::zero();
    while (beg != end) {
        Policy<AccT, T>::accumulate(total, *beg);
        ++beg;
    }
    return total;
}
} // namespace template_template_argument

int main(int argc, char* argv[]) {
    int num[] = {1, 2, 3, 4, 5};
    // using namespace version1;
    using namespace template_template_argument;
    std::cout << "the product of fthe integer values is "
              << accum<int, MulitPolicy>(num, num + 5) << '\n';
    // different policy for different traits
    return 0;
}
