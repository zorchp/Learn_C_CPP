#include <future>
#include <iostream>
using namespace std;


struct X {
    void foo(int, string const &);
    string bar(string const &);
};

X x;
auto f1 = async(&X::foo, &x, 42, "hello");
auto f2 = async(&X::bar, x, "bye");


struct Y {
    double operator()(double);
};

Y y;
auto f3 = async(Y(), 3.14);
auto f4 = async(std::ref(y), 2.71828);
X baz(X &);

auto f5 = async(baz, std::ref(x));

class move_only {
public:
    move_only();
    move_only(move_only &&);
    move_only(const move_only &) = delete;
    move_only &operator=(move_only &&);
    move_only &operator=(const move_only &) = delete;
    void operator()();
};

auto f6 = async(move_only());
