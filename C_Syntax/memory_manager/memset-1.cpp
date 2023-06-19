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
// -3 : -33686019
// -2 : -16843010
// -1 : -1
// 0 : 0
// 1 : 16843009
// 2 : 33686018
// 3 : 50529027
// 4 : 67372036
// 5 : 84215045
// 6 : 101058054
// 7 : 117901063
// 8 : 134744072
// 9 : 151587081
