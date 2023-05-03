#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>

using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}

void t1() {
    std::vector<int> v = {2, 2, 2, 2, 2,
                          2, 2, 2, 2, 2}; // 或 std::vector<int>v(10, 2);

    std::cout << "前 10 个偶数是：";
    std::partial_sum(v.begin(), v.end(),
                     std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>());

    std::cout << "2 的前 10 个幂是：";
    for (auto n : v) std::cout << n << " ";
    std::cout << '\n';
}


void t2() {
    vector<int> v{1, 2, 3, 4, 5};
    vector<int> ans(v.size() + 1);
    struct f {
        constexpr int operator()(const int& lhs, const int& rhs) const {
            return lhs + rhs;
        }
    };
    // partial_sum(v.begin(), v.end(), ans.begin() + 1, plus<int>());
    // partial_sum(v.begin(), v.end(), ans.begin() + 1, f());
    partial_sum(v.begin(), v.end(), ans.begin() + 1,
                [](const int& lhs, const int& rhs) { return lhs + rhs; });
    for (auto i : ans) cout << i << " ";
    cout << endl;
}

void t3() {
    vector<int> v{1, 2, 3, 4, 5};
    vector<int> ans(v.size() + 1);
    partial_sum(v.begin(), v.end(), ans.begin() + 1);
    cout << ans;
}

int main() {
    // t1();
    // t2();
    t3();
    return 0;
}