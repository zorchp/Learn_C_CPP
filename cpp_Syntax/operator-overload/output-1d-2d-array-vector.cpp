#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int LEN1 = 4, LEN2 = 2;
int a1[4]{1, 2, 3, 4};
int a2[4][2]{{1, 2}, {3, 4}, {5, 6}, {3, 2}};
vector<vector<int>> v1{{1, 2}, {3, 4}, {5, 6}};

ostream& operator<<(ostream& os, const vector<int>& v) {
    for (auto& i : v) os << i << " ";
    return os << endl;
}

ostream& operator<<(ostream& os, const vector<vector<int>>& v) {
    for (auto& i : v) os << i;
    return os;
}

ostream& operator<<(ostream& os, int* a) {
    for (int i{}; i < LEN2; ++i) os << a[i] << " ";
    return os << endl;
}

ostream& operator<<(ostream& os, int a[4][2]) {
    for (int i{}; i < LEN1; ++i) os << a[i];
    return os;
}


void t1() {
    // cout << typeid(a2).name() << endl; // A4_A2_i
    cout << a2;
    // cout << v1;
}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}