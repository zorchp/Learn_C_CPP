#include <bits/stdc++.h>
using namespace std;

vector<int> v{1, 2, 3, 4, 5};

void t1() {
    for (auto i : v) cout << i << " ";
    cout << endl;                 // 1 2 3 4 5
    cout << v.size() << endl;     // 5
    cout << v.capacity() << endl; // 5
    v.clear();
    for (auto i : v) cout << i << " ";
    cout << endl;
    cout << v.size() << endl;     // 0
    cout << v.capacity() << endl; // 5
}

void t2() {
    //
}

int main() { //
    t1();
    // t2();
}