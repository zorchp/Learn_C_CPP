#include <bits/stdc++.h>
// #define _(name) #name

using namespace std;

ostream &operator<<(ostream &os, const map<int, int> &mp) {
    os << "{";
    for (auto &[k, v] : mp) os << "<" << k << ": " << v << ">, ";
    return os << "}" << endl;
}

void t1() {
    map<int, int> m1;
    auto m2 = new map<int, int>();
    m1[12] = 123;
    m2->insert(pair<int, int>(1, 2));
    cout << "m1: " << m1;
    cout << "m2: " << *m2;
    cout << "m2->size() = " << m2->size() << endl;
    /*
    m1: {<12: 123>, }
    m2: {<1: 2>, }
    m2->size() = 1
    */
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}
