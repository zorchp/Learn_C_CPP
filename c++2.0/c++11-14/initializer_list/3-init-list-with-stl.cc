#include <bits/stdc++.h>
using namespace std;


void t1() {
    vector<int> v1{1, 2, 3, 4, 3};
    vector<int> v2({2, 3, 4});
    vector<int> v3;
    v3 = {1, 3, 4};
    v3.insert(v3.begin() + 1, {0, 0, 0});
    for (auto i : v3) cout << i << " ";
    cout << endl;
    cout << max({string("Fff"), string("Eoa"), string("Acc")}) << endl;
    cout << max({1, 23, 12, 2}) << endl;
    /*
    1 0 0 0 3 4
    Fff
    23
    */
}
int main(int argc, char const *argv[]) {
    t1();
    return 0;
}