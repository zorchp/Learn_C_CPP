#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

// just for gcc
// template <typename T, template <typename> class Container>
// ostream &operator<<(ostream &os, const Container<T> v) {
//     for (auto i : v) os << i << " ";
//     return os;
// }

template <typename T>
ostream &operator<<(ostream &os, const list<T> v) {
    for (auto i : v) os << i << " ";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const deque<T> v) {
    for (auto it = v.begin(); it != v.end(); ++it) os << *it << " ";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> v) {
    for (auto i : v) os << i << " ";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> v) {
    for (auto i : v) os << i;
    return os;
}

void t1() {
    deque<int> a{1, 2, 3};
    cout << a;
}
void t2() {
    ll a = 1;
    cout << a;
}


int main(int argc, char *argv[]) {
    t1();
    /* t2(); */
    return 0;
}
