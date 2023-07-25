#include <iostream>

using namespace std;

//  这个函数必须要加, 相当于设置了迭代的终止
void printX() {}

template <typename T, typename... Types>
void printX(const T& firstArg, const Types&... args) {
    cout << firstArg;
    cout << (sizeof...(args) ? ", " : ". \n");
    printX(args...); //调用函数进行处理
}

int main(int argc, char const* argv[]) {
    printX(1, 2.0, bitset<12>(399), "3re");
    return 0;
}