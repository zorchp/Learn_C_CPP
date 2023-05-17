#include <bits/stdc++.h>
using namespace std;

// unordered_set<char> dic{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
static const string dc = "aeiouAEIOU"s;
static unordered_set<char> dic(dc.begin(), dc.end());

void t0() {
    string s;
    vector<string> vs;
    // 可以通过的写法, 但是需要额外空间
    while (cin >> s) {
        if (s.empty()) break;
        vs.emplace_back(s);
    }

    auto N = vs.size();
    for (int i{}; i < N; ++i) {
        for (auto& c : vs[i]) {
            if (dic.count(c))
                c = toupper(c);
            else
                c = tolower(c);
        }
        cout << vs[i] << (i == N - 1 ? "" : " ");
    }
}

void t1() {
    string s, t;
    vector<string> vs;
    getline(cin, s);
    stringstream ss(s);
    // 可以通过的写法, 但是需要额外空间
    while (ss >> t) {
        vs.emplace_back(t);
    }

    auto N = vs.size();
    for (int i{}; i < N; ++i) {
        for (auto& c : vs[i]) {
            if (dic.count(c))
                c = toupper(c);
            else
                c = tolower(c);
        }
        cout << vs[i] << (i == N - 1 ? "" : " ");
    }
}

void t2() {
    string s, t;
    getline(cin, s);
    stringstream ss(s);
    ostringstream oss;
    while (ss >> t) {
        for (auto& c : t) {
            if (dic.count(c))
                c = toupper(c);
            else
                c = tolower(c);
        }
        oss << t << " ";
    }
    auto ans = oss.str();
    // ans.pop_back();
    cout << ans;
}

int main() {
    t0();
    // t1();
    return 0;
}
