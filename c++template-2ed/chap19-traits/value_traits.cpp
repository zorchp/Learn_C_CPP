template <typename T>
struct AccumulationTraits;

template <>
struct AccumulationTraits<char> {
    using AccT = int;
    static AccT constexpr zero = 0;
};

template <>
struct AccumulationTraits<short> {
    using AccT = int;
    static AccT constexpr zero = 0;
};

template <>
struct AccumulationTraits<int> {
    using AccT = long;
    static AccT constexpr zero = 0;
};
template <>
struct AccumulationTraits<float> {
    using AccT = double;
    static AccT constexpr zero = 0.;// must use constexpr
};

template <>
struct AccumulationTraits<unsigned int> {
    using AccT = unsigned long;
    static AccT constexpr zero = 0;
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
