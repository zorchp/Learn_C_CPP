#include <vector>
#include <iostream>
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> v) {
    for (auto i : v) os << i;
    return os << endl;
}

void t1() {
    vector<vector<int>> v{};
    v.emplace_back(vector<int>{3, 2});
    cout << v; // 3 2
}

void t11() {
    vector<vector<int>> v{};
    v.emplace_back(vector<int>(3, 2));
    cout << v; // 2 2 2
}

void t2() {
    auto v = vector<int>{3, 2};
    cout << v; // 3 2
}

void t21() {
    vector<int> v{3, 2};
    cout << v; // 3 2
}

void t4() {
    //
}

int main(int argc, char const *argv[]) {
    // t1();
    // t11();
    // t2();
    // t21();
    t4();
    return 0;
}
