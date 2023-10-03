#include <bits/stdc++.h>
using namespace std;

void t1() {
    vector v = {3, 2, 3, 2, 4, 5};
    sort(v.begin(), v.end(), [](int a, int b) { return a <= b; });
    for (int i : v) {
        cout << i << " ";
    }
    cout << '\n';
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
