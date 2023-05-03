#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    double maxProfit(double origin, vector<double>& prices, int k) {
        // cache + dfs
        // int n = prices.size(), cache[n][k+1][2];
        // function<int(int, int, int)> dfs = [&](int i, int j, int hold) -> int
        // {
        //     if ( i<0 )
        //         return hold ? -INT_MAX/2 : origin;
        //     if ( j<0 )
        //         return -INT_MAX/2;
        //     if ( cache[i][j][hold]!=-1 )
        //         return cache[i][j][hold];
        //     if ( hold )
        //         return cache[i][j][hold] = max(dfs(i-1, j-1,
        //         false)/prices[i], dfs(i-1, j, true));
        //     return cache[i][j][hold] = max(dfs(i-1, j, true)*prices[i],
        //     dfs(i-1, j, false));
        // };

        // // iteration
        // int n = prices.size();
        // double f[n+1][k+2][2];
        // memset(f, -(double)0x3f, sizeof(f));
        // for ( int j=0;j<=k+1;++j ) f[0][j][false] = origin;
        // for ( int i=0;i<n;++i ) {
        //     for ( int j=0;j<k+1;++j ) {
        //         f[i+1][j+1][true] = max(f[i][j][false]/prices[i],
        //         f[i][j+1][true]); f[i+1][j+1][false] =
        //         max(f[i][j+1][true]*prices[i], f[i][j+1][false]);
        //     }
        // }
        // return f[n][k+1][false]-origin;

        // space optimized
        int n = prices.size();
        double f[k + 2][2];
        memset(f, -(double)0x3f, sizeof(f));
        for (int j = 0; j <= k + 1; ++j) f[j][false] = origin;
        for (int i = 0; i < n; ++i) {
            for (int j = k; j >= 0; --j) {
                f[j + 1][true] = max(f[j][false] / prices[i], f[j + 1][true]);
                f[j + 1][false] =
                    max(f[j + 1][true] * prices[i], f[j + 1][false]);
            }
        }
        return f[k + 1][false] - origin;
    }
};


int main(int argc, char const* argv[]) {
    Solution s;
    vector<double> v{1, 2, 1, 2, 2, 3, 2};
    cout << s.maxProfit(10000, v, 2);
    return 0;
}