#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        srand(time(0));
        unordered_map<int, int> cnt;
        for (auto num : nums) ++cnt[num];
        vector<pair<int, int>> pairs(cnt.begin(), cnt.end());
        int n = pairs.size();

        vector<int> ans;
        auto partition = [&](int l, int r) {
            swap(pairs[rand() % (r - l + 1) + l], pairs[r]); // random
            int pivot{pairs[r].second}, i{l};
            for (int j{l}; j < r; ++j)
                if (pairs[j].second >= pivot) swap(pairs[i++], pairs[j]);
            swap(pairs[i], pairs[r]);
            return i; // pivot 新位置
        };
        function<void(int, int, int)> quickSelect = [&](int l, int r, int k) {
            int m = partition(l, r);
            if (k <= m - l)
                quickSelect(l, m - 1, k); // 不满足条件
            else {
                for (int i{l}; i <= m; ++i) ans.emplace_back(pairs[i].first);
                if (k > m - l + 1) quickSelect(m + 1, r, k - (m - l + 1));
            }
        };
        quickSelect(0, n - 1, k);
        return ans;
    }
};

Solution s;
void t1() {
    std::vector<int> nums{1, 1, 1, 2, 2, 3};
    int k{2};
    for (auto i : s.topKFrequent(nums, k)) std::cout << i << " ";
    std::cout << '\n';
}
void t2() {
    std::vector<int> nums{1};
    int k{1};
    for (auto i : s.topKFrequent(nums, k)) std::cout << i << " ";
    std::cout << '\n';
}

int main(int argc, char const* argv[]) {
    t1();
    // t2();
    return 0;
}
