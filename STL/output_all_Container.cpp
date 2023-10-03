#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

template <typename T, template <typename> class Container>
ostream &operator<<(ostream &os, const Container<T> v) {
    for (auto i : v) os << i << " ";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const list<T> &v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}

template <typename T>
ostream &operator<<(ostream &os, const deque<T> &v) {
    for (auto it = v.begin(); it != v.end(); ++it) os << *it << " ";
    return os << endl;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    for (auto i : v) os << i;
    return os << endl;
}

template <typename T>
ostream &operator<<(ostream &os, stack<T> st) { // pass by value
    for (; !st.empty(); st.pop()) os << st.top() << " ";
    return os << endl;
}

template <typename T>
ostream &operator<<(ostream &os, queue<T> st) { // pass by value
    for (; !st.empty(); st.pop()) os << st.front() << " ";
    return os << endl;
}

template <typename T>
ostream &operator<<(ostream &os, priority_queue<T> st) { // pass by value
    for (; !st.empty(); st.pop()) os << st.top() << " ";
    return os << endl;
}

void t1() {
    // list<int> a{1, 2, 3};
    vector<int> v{1, 9, 2, 10, 8, 5};
    priority_queue<int> pq(v.begin(), v.end());
    cout << pq;
    cout << pq.empty();
}
void t2() {
    ll a = 1;
    cout << a;
}


int main(int argc, char *argv[]) {
    t1();
    // t2();
    return 0;
}
