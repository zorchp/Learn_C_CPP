#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(int i) { return i < 3; }

void t1() {
    vector<int> v{1, 2, 3, 4, 5};

    // ptr_fun将函数(传入值是函数名, 即函数指针)包裹为函数对象
    // deprecated in C++17
    // auto it = find_if(v.begin(), v.end(), ptr_fun(check));

    // C++11
    // auto it = find_if(v.begin(), v.end(), function<bool(int)>(check));
    auto it = find_if(v.begin(), v.end(), [](int x) { return x < 3; });

    cout << *it << endl; // 1
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}