#include <iostream>
#include <vector>
using namespace std;
void t1() {
    int a[10];
    for (auto i : a) cout << i << " ";
    cout << endl; // 7880816 1 3603960 1 3653728 1 1873358624 1 7531648
                  // 840073217
}
void t2() {
    vector<int> v(10);
    int n = v.size();
    int a[1 + n]{};
    for (auto i : a) cout << i << " ";
    cout << endl; // 0 0 0 0 0 0 0 0 0 0
}


void t3() {
    Solution s;
    vector<int> v{1, 2, 3};
    cout << s.longestWPI(v) << endl;
}

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}
