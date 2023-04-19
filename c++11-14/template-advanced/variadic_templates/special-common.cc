#include <iostream>

using namespace std;


void print() {}

// 特化
template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {
    cout << firstArg << ", ";
    print(args...);
}

// 泛化版本, 只要与上面的函数同时存在就不会被调用
template <typename... Types>
void print(const Types&... args) {}

// template<class ...Us> void f(Us... pargs) {}
// template<class ...Ts> void g(Ts... args) {
//     f(&args...); // “&args...” 是包展开
//                  // “&args” 是其模式
// }

int main(int argc, char const* argv[]) {
    print(1, 2, "dde", true, bitset<10>(377));
    // g(1, 0.2, "a");
    return 0;
}
