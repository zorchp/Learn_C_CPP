#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    for (auto i : v) os << i;
    return os << endl;
}
void t1() {
    string row;
    std::ios::sync_with_stdio(false); // 取消 cin 和 stdin 的同步
    while (getline(cin, row)) {
        vector<int> tmp;
        int item;
        istringstream ss(row);
        while (ss >> item) {
            tmp.emplace_back(item);
        }
        ans.emplace_back(tmp);
        if (row.empty()) break; // 换行时结束
    }
    cout << ans;
}

void t2() {
    // 容器还是用 vector, 但是 IO 采用 C 风格
    char buf[10]{};
    auto atoi = [](char *buf) {
        int ans{};
        for (int i{}; buf[i] != '\0'; ++i) ans = ans * 10 + (buf[i] - '0');
        return ans;
    };
    vector<int> tmp;
    while (~scanf("%[^ \n]", buf)) {
        tmp.emplace_back(atoi(buf));
        if (getchar() == '\n') {
            ans.emplace_back(tmp);
            cout << tmp;
            tmp.clear();
            // if (getchar() == '\n') break;
        }
    }
    cout << ans;
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
