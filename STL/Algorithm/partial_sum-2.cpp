#include <vector>
#include <iostream>
#include <iterator>
#include <numeric>
#include <functional>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (auto i : v) os << i;
    return os << endl;
}

const std::vector<std::vector<int>> v1{
    {0, 3, 6, 9, 7, 5, 0}, {0, 4, 12, 8, 10, 3, 0}, {0, 12, 11, 6, 4, 7, 0}};
int m = v1.size(), n = v1[0].size();

void t1() {
    cout << v1;
    vector<vector<int>> ans_col(m, vector<int>(n + 1));
    for (int i{}; i < m; ++i)
        partial_sum(v1[i].begin(), v1[i].end(), ans_col[i].begin() + 1);
    cout << ans_col;
}

void t2() {
    cout << v1;
    vector<vector<int>> ans_row(n, vector<int>(m + 1));
    for (int i{}; i < n; ++i)
        partial_sum(v1[i].begin(), v1[i + m].begin(), ans_row[i]);
}

int main() {
    /* t1(); */
    t2();
    return 0;
}
