#include <bits/stdc++.h>
#include <list>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto i : v)
        os << i << " ";
    return os << '\n';
}

void print_arr(int arr[], size_t n) { // C-style array need length
    for (int i{}; i < n; ++i)
        cout << arr[i] << " ";
    cout << '\n';
}

void t1() {
    int arr[]{1, 9, 3, 32, 8, 6};
    auto n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n); // 顺序(增序)
    print_arr(arr, n);
    sort(arr, arr + n, greater<>()); // 逆序
    print_arr(arr, n);
    // 1 3 6 8 9 32
    // 32 9 8 6 3 1
}

void t2() {
    vector<int> v{1, 32, 9, 8, 6, 3};
    sort(v.begin(), v.end());
    cout << v;
    sort(v.rbegin(), v.rend());
    cout << v;
    // 1 3 6 8 9 32
    // 32 9 8 6 3 1
}
void t3() {
    vector<int> v{1, 32, 9, 8, 6, 3};
    sort(v.begin(), v.end(),
         [](const auto& lhs, const auto& rhs) { return lhs % 4 < rhs % 4; });
    cout << v; // 32 8 1 9 6 3
}

void t4() {
    vector<vector<int>> vv{
        {1, 2}, {2, 9}, {2, 3}, {0, 8}, {1, 1} //
    };
    sort(vv.begin(), vv.end(), [](const auto& lhs, const auto& rhs) {
        return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
    });
    cout << vv;
    // 0 8
    //  1 1
    //  1 2
    //  2 3
    //  2 9
}
void t5() {
    list<int> l1{1, 2, 9, 29, 4, 294, 219, 1, 1, 3};
    // sort(l1.begin(), l1.end()); // error
    cout << __CHAR_BIT__; // 8
}
int main(int argc, char* argv[]) {
    // t1();
    // t2();
    // t3();
    // t4();
    t5();
    //
    return 0;
}
