#include <bits/stdc++.h>
using namespace std;

void init(int x) {
    int a[10];
    memset(a, x, sizeof(a));
    for (int i{}; i < 1; ++i) //
        cout << x << " : " << a[i] << endl;
}

int main(int argc, char* argv[]) {
    //
    for (int i{-3}; i < 10; ++i) {
        init(i);
    }
    return 0;
}

