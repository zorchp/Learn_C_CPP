#include <bits/stdc++.h>
using namespace std;


void t1() {
    vector<int> vi{5, 32, 2, 2, 2, 3, 5, 35, 353};
    for (auto &i : vi) cout << i << " ";
    cout << endl;
    int x = 3, y = 40;
    vi.erase(remove_if(vi.begin(), vi.end(),
                       [x, y](int n) { return n > x && n < y; }),
             vi.end());
    for (auto &i : vi) cout << i << " ";
    cout << endl;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}