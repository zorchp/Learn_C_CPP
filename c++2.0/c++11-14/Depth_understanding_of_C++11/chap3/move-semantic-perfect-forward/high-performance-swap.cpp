#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
void perfect_swap(T& a, T& b) {
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}
void t1() {
    int a = 10, b = 20;
    cout << a << " " << b << endl;
    perfect_swap(a, b);
    cout << a << " " << b << endl;
}
struct P {
    P() noexcept { throw; }
    P(P&&) noexcept {};
};
struct Q {
    Q() = default;
    Q& operator=(Q&&) = default;
};

template <typename T>
void test_moveable(T t) {
    cout << is_move_constructible<T>::value << endl;
    cout << is_move_assignable<T>::value << endl;
    cout << is_trivially_move_constructible<T>::value << endl;
    cout << is_trivially_move_assignable<T>::value << endl;
    cout << is_nothrow_move_constructible<T>::value << endl;
    cout << is_nothrow_move_assignable<T>::value << endl;
}
void t2() {
    /* test_moveable(int()); */
    test_moveable(P());
    /* test_moveable(Q()); */
}

int main() {
    /* t1(); */
    t2();
    return 0;
}
