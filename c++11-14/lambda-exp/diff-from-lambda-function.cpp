#include <iostream>
#include <functional>
#include <typeinfo>
using namespace std;


int main(int argc, char const *argv[]) {
    auto f1 = [&](int a) -> int { return a; };
    function<int(int)> f2 = [&](int a) { return a; };
    cout << typeid(f1).name() << endl; // Z4mainE3$_1
    cout << typeid(f2).name() << endl; // NSt3__18functionIFiiEEE

    cout << typeid(decltype(f1)).name() << endl; // Z4mainE3$_1
    cout << typeid(decltype(f2)).name() << endl; // NSt3__18functionIFiiEEE

    return 0;
}