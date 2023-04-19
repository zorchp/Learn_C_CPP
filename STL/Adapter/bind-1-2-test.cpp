#include <algorithm>
#include <functional> //bind
#include <iostream>
#include <vector>
using namespace std;
using namespace std::placeholders;

void t1() {
    auto b1 = bind(multiplies<int>(), bind(plus<int>(), _1, 10), 2); // not good
    auto b2 = [](int x) { return (x + 10) * 2; };                    // best

    cout << b1(10) << endl; // 40
    cout << b2(10) << endl; // 40
}

void t2() {
    auto b1 =
        bind(multiplies<int>(), bind(plus<int>(), _1, _3), _2); // not good
    auto b2 = [](int x, int y, int z) { return (x + z) * y; };  // best

    cout << b1(10, 10, 20) << endl; // 300
    cout << b2(10, 10, 20) << endl; // 300
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}