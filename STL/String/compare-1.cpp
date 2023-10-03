#include <bits/stdc++.h>
using namespace std;

string s = "abc";
string t = "def";

void t1() {
    cout << (s < t) << endl;        // 1
    cout << (s.compare(t)) << endl; //-3
    cout << (t.compare(t)) << endl; // 0
    cout << (t.compare(s)) << endl; // 3
}

void t2() {
    auto ans{s <=> t};
    // cout << typeid(ans).name() << endl;
    if (is_lt(ans)) {
        cout << "less\n";
    } else if (is_gt(ans)) {
        cout << "greater\n";
    } else {
        cout << "equal\n";
    }
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
