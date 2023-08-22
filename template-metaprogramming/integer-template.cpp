template <class T, T v>
struct integral_constant {
    static const T val = v;
    typedef T value_type;
    typedef integral_constant type;
};
