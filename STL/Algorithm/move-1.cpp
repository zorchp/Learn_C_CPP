#include <bits/stdc++.h>
#include <iterator>
#include <list>
#include <ostream>
using namespace std;
ostream &operator<<(ostream &os, const vector<int> &v) {
    for (auto i : v) {
        os << i << " ";
    }
    return os << endl;
}

void t1() {
    vector<int> v{1, 2, 3, 4, 5};
    move(v.begin(), v.begin() + 2, v.begin() + 3);
    cout << v;                              // 1 2 3 1 2
    auto x = remove(v.begin(), v.end(), 2); // remove all 2 in v
    cout << v;                              // 1 3 1 1 2
    // cout << *x << endl;                     // 1
    cout << distance(v.begin(), x) << endl; // 3
    v.erase(x, v.end());
    cout << v; // 1 3 1
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
