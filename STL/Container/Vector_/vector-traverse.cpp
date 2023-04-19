#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T> v) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); it++)
        os << *it << (it < v.end() - 1 ? ", " : "]");
    os << endl;
    return os;
}

// template<typename T>
// T operator[](const vector<T> &v, T &idx) {
//     return v.at(idx);
// }

void test1() {
    // 尾插法插入元素
    vector<int> v;
    for (int i = 0; i < 10; i++) { v.push_back(i * 2 + 1); }
    cout << v;
    v[2]    = 10000;
    v.at(1) = 22;
    cout << v;
    sort(v.rbegin(), v.rend());
    cout << v;
}

int main(int argc, char const* argv[]) {
    test1();
    return 0;
}