#include <bits/stdc++.h>
using namespace std;

vector<int> v(0);

void t1() {
    cout << v.at(0) << endl; // libc++abi: terminating with uncaught
    // exception of type std::out_of_range: vector
}

void t2() {
    cout << v[0] << endl; // runtime error: reference binding to null pointer of
                          // type 'int'
}
void t3() {
    try {
        cout << v.at(0) << endl;
    } catch (std::out_of_range) {
        cout << "out_of_range\n"; // out_of_range
    }
}

int main() { //
    // t1();
    // t2();
    t3();
}