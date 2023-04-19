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
        ans.emplace_back(string(tmp));
        if (getchar() == '\n') {
            sort(ans.begin(), ans.end());
            for (auto s : ans) cout << s << " ";
            putchar('\n');
            ans.clear();
        }
    }

    return 0;
}
