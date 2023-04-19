#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const* argv[]) {
    //
    vector<int> v{2, 4, 1, 3, 5};
    for (auto i : v)
        if (0 == i % 2) remove(v.begin(), v.end(), i);
    for (auto i : v) cout << i << " ";
    cout << endl; // 4 1 3 5 5
    return 0;
}
