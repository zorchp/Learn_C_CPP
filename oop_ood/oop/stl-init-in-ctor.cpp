#include <vector>
#include <list>
#include <iostream>
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> v) {
    os << "[ ";
    for (auto i : v) os << i << " ";
    return os << "]\n";
}
template <typename T>
ostream &operator<<(ostream &os, const list<T> v) {
    os << "[ ";
    for (auto i : v) os << i << " ";
    return os << "]\n";
}

class P {
private:
    // vector<vector<int>> v{{1, 2}, {3, 4, 5}}; // ok
    vector<vector<int>> v(10, vector<int>(10)); // error
    // vector<vector<int>> v = vector<vector<int>>(10, vector<int>(10)); // ok
    // vector<int> v = vector<int>(10);
    // const static int base = 10;

public:
    // P() : v(base) {}
    P() {}
    void print() {
        for (auto &i : v) {
            for (auto &j : i) cout << j << " ";
            cout << endl;
        }
    }
};
// const int P::base;

void t1() {
    P p;
    //
    p.print();
}

void t2() {
    vector<vector<int>> v(769, vector<int>()); //
}

int main(int argc, char const *argv[]) {
    t1();
    // t2();
    return 0;
}