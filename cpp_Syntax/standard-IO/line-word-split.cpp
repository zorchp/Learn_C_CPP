#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> ans{};
void t1() {
    while (cin >> s) {
        ans.emplace_back(s);
        if (cin.get() == '\n') break;
    }
}

void t2() {
    stringstream ss;
    while (cin >> ss) { ans.emplace_back(ss); }
}

int main(int argc, char const *argv[]) {
    // t1();
    for (auto s : ans) cout << s << endl;
    return 0;
}