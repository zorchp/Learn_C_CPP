#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    char tmp[1000]; // 必须给出数据范围
    scanf("%d", &n);
    vector<string> ans(n);
    while (n--) {
        scanf("%s", tmp);
        ans[n] = string(tmp);
    }
    sort(ans.begin(), ans.end());
    for (auto s : ans) cout << s << " ";
    return 0;
}
