#include <bits/stdc++.h>

using namespace std;

void t1() {
    vector<int> v;
    cout << v.size() << " " << v.capacity() << endl;
    for (int i{}; i < 513; ++i) {
        v.emplace_back(i);
        if (i >= 511) cout << v.size() << " " << v.capacity() << endl;
    }
    // 0 0
    // 512 512
    // 513 1024
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
