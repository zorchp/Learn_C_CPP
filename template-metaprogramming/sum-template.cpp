#include <cstdio>

template <class T, T v>
struct integral_constant {
    static const T val = v;
    typedef T value_type;
    typedef integral_constant type;
};

template <bool cond, typename Body>
struct WhileLoop;


template <typename Body>
struct WhileLoop<true, Body> {
    typedef typename WhileLoop<Body::cond_value, typename Body::next_type>::type
        type;
};

template <typename Body>
struct WhileLoop<false, Body> {
    typedef typename Body::res_type type;
};

template <typename Body>
struct While {
    typedef typename WhileLoop<Body::cond_value, Body>::type type;
};

template <int result, int n>
struct SumLoop {
    static const bool cond_value = n != 0;
    static const int res_value = result;
    typedef integral_constant<int, res_value> res_type;
    typedef SumLoop<result + n, n - 1> next_type;
};

template <int n>
struct Sum {
    typedef SumLoop<0, n> type;
};

int main(int argc, char *argv[]) {
    printf("%d\n", While<Sum<10>::type>::type::val);
    return 0;
}
