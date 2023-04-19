#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    char tmp[1000]; // 必须给出数据范围
    vector<string> ans;
    while (~scanf("%s", tmp)) {
        string stmp = string(tmp), ss{};
        for (int i{}; i < stmp.size(); ++i) {
            if (isalpha(stmp[i]))
                ss += stmp[i];
            else
                ans.emplace_back(ss), ss.clear();
        }
        ans.emplace_back(ss);
        sort(ans.begin(), ans.end());
        for (int i{}; i < ans.size(); ++i)
            cout << ans[i] << (i == ans.size() - 1 ? "\n" : ",");
        ans.clear();
    }

    return 0;
}
