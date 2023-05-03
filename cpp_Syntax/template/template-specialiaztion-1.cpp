#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct hash1 {};

// 特化
template <>
struct hash1<char> {
    size_t operator()(char x) const { return x; }
};

// 特化
template <>
struct hash1<long> {
    size_t operator()(long x) const { return x; }
};

// 特化
template <>
struct hash1<int> {
    size_t operator()(int x) const { return x; }
};

void t1() {
    cout << hash1<char>()('a') << endl;
    cout << hash1<int>()(12) << endl;
    cout << hash1<long>()(1000000L) << endl;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}
