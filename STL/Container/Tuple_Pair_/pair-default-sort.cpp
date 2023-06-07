#include <bits/stdc++.h>


using namespace std;
using pii = pair<int, int>;

void t1() {
    vector<pii> v{
        {1, 2}, {1, 1}, {3, 2}, {3, 0}, {2, 2} //
    };
    sort(v.begin(), v.end());
    for (auto [p1, p2] : v) cout << p1 << " : " << p2 << endl;
    // 1 : 1
    // 1 : 2
    // 2 : 2
    // 3 : 0
    // 3 : 2
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
