#include <iostream>
#include <queue>
#include <vector>
#include <typeinfo>
#include <type_traits>


using namespace std;


ostream &operator<<(ostream &os, const vector<int> &c) {
    for (auto i : c) os << i << " ";
    return os << endl;
}

// template <>
// ostream &operator<<(ostream &os, const priority_queue<int> &p) {
//     priority_queue<int> tmp(p);
//     int n = tmp.size();
//     for (int i{}; i < n; ++i) {
//         os << tmp.top() << " ";
//         tmp.pop();
//     }
//     return os << endl;
// }


void t1() {
    cout << typeid(priority_queue<int>::container_type).name() << endl;
    // The type of first-class container upon which a container adaptor is
    // based.
    // 容器适配器所基于的一级容器类型。
    cout << typeid(vector<int>).name() << endl;
    //=========================================
    cout << typeid(priority_queue<int>).name() << endl;
    cout << typeid(priority_queue<int, vector<int>, less<int>>).name() << endl;
    cout << typeid(priority_queue<int, vector<int>, greater<int>>).name()
         << endl;
    cout << typeid(priority_queue<int, vector<int>>).name() << endl;
    cout << typeid(priority_queue<less<int>>).name() << endl;
    cout << typeid(priority_queue<greater<int>>).name() << endl;
}
#if 0
St6vectorIiSaIiEE
St6vectorIiSaIiEE
St14priority_queueIiSt6vectorIiSaIiEESt4lessIiEE
St14priority_queueIiSt6vectorIiSaIiEESt4lessIiEE
St14priority_queueIiSt6vectorIiSaIiEESt7greaterIiEE
St14priority_queueIiSt6vectorIiSaIiEESt4lessIiEE
St14priority_queueISt4lessIiESt6vectorIS1_SaIS1_EES0_IS1_EE
St14priority_queueISt7greaterIiESt6vectorIS1_SaIS1_EESt4lessIS1_EE
#endif

template <typename Q, template <typename> class Comp>
ostream &operator<<(ostream &os, priority_queue<Comp<Q>, vector<Q>> q) {
    for (; !q.empty(); q.pop()) { os << q.top() << " "; }
    return os << endl;
}

template <typename Q, template <typename> class Comp>
ostream &operator<<(ostream &os, priority_queue<Q, vector<Q>, Comp<Q>> q) {
    for (; !q.empty(); q.pop()) { os << q.top() << " "; }
    return os << endl;
}


// template <typename Q>
// ostream &operator<<(ostream &os, priority_queue<Q> q) {
//     for (; !q.empty(); q.pop()) { os << q.top() << " "; }
//     return os << endl;
// }


void t2() {
    priority_queue<int, vector<int>, less<int>> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    for (auto i : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        q1.push(i);
        q2.push(i);
    }
    cout << q1;
    cout << q2;
    cout << q1.size() << endl;
    cout << q2.size() << endl;
    /*
    9 8 7 6 5 4 3 2 1 0
    0 1 2 3 4 5 6 7 8 9
    10
    10*/
}

void t3() {
    const auto v = {1, 0, 5, 4, 9, 7, 6, 2};
    cout << v;
    // cout << typeid(v).name() << endl;
    // St16initializer_listIiE
    priority_queue q3(v.begin(), v.end(), less<int>(), vector<int>());
    priority_queue q4(v.begin(), v.end(), greater<int>(), vector<int>());
    cout << typeid(q3).name() << endl;
    // NSt3__114priority_queueIiNS_6vectorIiNS_9allocatorIiEEEENS_4lessIiEEEE
    cout << q3;
    cout << q4;
    cout << q3.size() << endl;
    cout << q4.size() << endl;
    /*
    1 0 5 4 9 7 6 2
    9 7 6 5 4 2 1 0
    0 1 2 4 5 6 7 9
    8
    8
    */
}

void t4() {
    priority_queue q5{less<int>(), vector<int>()};
    priority_queue q6{greater<int>(), vector<int>()};
    // cout << typeid(q5).name() << endl;
    // St14priority_queueIiSt6vectorIiSaIiEESt4lessIiEE
    for (int i : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        q5.emplace(i);
        q6.emplace(i);
    }
    cout << q5;
    cout << q6;
    /*9 8 7 6 5 4 3 2 1 0
    0 1 2 3 4 5 6 7 8 9*/
}
int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}
