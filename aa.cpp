#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        function<int(int, int)> f = [&](int x, int y) {
            if (x == m - 1 && y == n - 1) return 1;
            if (x < m && y < n && g[x][y]) // 有石头
                return 0;
            return f(x + 1, y) + f(x, y + 1);
        };
        return f(0, 0);
    }
};

int main(int argc, char const* argv[]) {
    //
    vector<vector<int>> v{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution s;
    cout << s.uniquePathsWithObstacles(v);
    return 0;
}
