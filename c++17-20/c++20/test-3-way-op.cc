// C++ program to illustrate the
// above concepts
#include <iostream>
#include <vector>

// #include <compare>//3ways op
using namespace std;

void t1() {
    int a = 91, b = 110;
    auto ans1 = a <=> b;

    if (ans1 < 0) {
        cout << "a < b\n";
    } else if (ans1 == 0) {
        cout << "a == b\n";
    } else if (ans1 > 0) {
        cout << "a > b\n";
    }
    cout << typeid(ans1).name() << endl;
    // St15strong_ordering
}

void t2() {
    vector<int> v1{3, 6, 9};
    vector<int> v2{3, 6, 9};
    auto ans2 = v1 <=> v2;

    if (ans2 < 0) {
        cout << "v1 < v2\n";
    } else if (ans2 == 0) {
        cout << "v1 == v2\n";
    } else if (ans2 > 0) {
        cout << "v1 > v2\n";
    }
}

// Driver Code
int main() {
    t1();
    t2();
}
