#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    char tmp[100]; // 必须给出数据范围
    vector<string> ans;
    // %[^,]遇到逗号停止
    while (~scanf("%[^,\n]", tmp)) {
        ans.emplace_back(string(tmp));
        if (getchar() == '\n') {
            sort(ans.begin(), ans.end());
            for (auto it = ans.begin(); it != ans.end(); ++it)
                cout << *it << (it == ans.end() - 1 ? "\n" : ",");
            ans.clear();
            // if (getchar() == '\n') break;
        }
    }
    return 0;
}
