#include <bits/stdc++.h>
using namespace std;


void t1() {
    vector<int> v1{1, 2, 3, 4, 3};
    for (auto &i : v1) cout << i << ", ";
    cout << endl;
    vector<vector<int>> v2(3, {1, 2, 3, 4, 5});
    for (auto &i : v2) {
        for (auto &j : i) {
            j += (j % 5);
            cout << j << " ";
        }
        cout << endl;
    }
    /*
    1, 2, 3, 4, 3,
    2 4 6 8 5
    2 4 6 8 5
    2 4 6 8 5
    */
}

class C {
public:
    string s;
    // explicit
    C(const string &s1) : s(s1){};
};

ostream &operator<<(ostream &os, C c) {
    os << c.s;
    return os;
}

void t2() {
    vector<string> vs{"'a'", "abc"};
    // cout << typeid(vs).name() << endl;
    for (const C &it : vs) cout << it << " ";
    cout << endl;
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}