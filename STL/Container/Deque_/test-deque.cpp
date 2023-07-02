#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, deque<T> dq) {
    os << "[";
    for (auto it = dq.begin(); it < dq.end(); it++)
        os << *it << (it < dq.end() - 1 ? ", " : "]");
    os << endl;
    return os;
}

void t1() {
    deque<int> dq{1, 2, 3, 5, 6, 7, 9};
    cout << dq;
    cout << "dq[2]=" << dq[2] << endl;
    deque<int>::iterator it = find(dq.begin(), dq.end(), 5);
    cout << "dq[2]=" << *(it) << endl;
    dq.pop_back();
    cout << dq;
    dq.pop_front();
    cout << dq;
    dq.push_front(12);
    cout << dq;
    dq.push_back(9);
    cout << dq;
    /*
    [1, 2, 3, 5, 6, 7, 9]
    dq[2]=3
    [1, 2, 3, 5, 6, 7]
    [2, 3, 5, 6, 7]
    [12, 2, 3, 5, 6, 7]
    [12, 2, 3, 5, 6, 7, 9]
    */
}

void t2() {
    deque<int> c{1, 2, 3, 5, 6, 7, 9};
    cout << "deque.size()= " << c.size() << endl;
    cout << "deque.front()= " << c.front() << endl;
    cout << "deque.back()= " << c.back() << endl;
    cout << "deque.max_size()= " << c.max_size() << endl;
    /*
    deque.size()= 7
    deque.front()= 1
    deque.back()= 9
    deque.max_size()= 4611686018427387903
    */
}

void t3() {
    deque<int> dq{1, 2, 3, 5, 6, 7, 9};
    auto it = find(dq.begin(), dq.end(), 5);
    cout << *it << endl;      // 5
    cout << (int&)it << endl; // 1340097852
}

void t4() {
    deque<int> dq{1, 2, 3};
    cout << accumulate(dq.begin(), dq.end(), 0) << endl;
}

int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}
