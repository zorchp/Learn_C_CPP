#include <bits/stdc++.h>
using namespace std;

// typedef void(*func)(int,int);
using func = void (*)(int, int);

void example(int a, int b) { cout << a << " " << b << endl; }
void t1() {
    // func is a type
    func fn = example; // func ptr
    fn(1, 2);
}

template <typename T>
struct Container {
    using value_type = T;
    // typedef T value_type;//equal to
};

template <typename Cntr>
void fn2(const Cntr& c) {
    typename Cntr::value_type n;
}

// alias template, can only use `using`
template <class CharT>
using mystring = basic_string<CharT, char_traits<CharT>>;

void t2() { mystring<char> str; }

// use typedef:error
/*template <class CharT1>
void t3() {
    typedef basic_string<CharT1, char_traits<CharT1>> mystring;
    mystring<char> str;
}
*/
int main(int argc, char const* argv[]) {
    // t1();
    t2();
    // t3();
    return 0;
}