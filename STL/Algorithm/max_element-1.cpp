#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// vector<vector<int>> f() { return {}; }

int main(int argc, char const *argv[]) {
    std::vector<int> v{1};
    v.pop_back();
    for (auto i : v) cout << i << endl; // 未执行

    cout << *max_element(v.begin(), v.end()) << endl; // 1
    // return the last if vector is empty
    return 0;
}