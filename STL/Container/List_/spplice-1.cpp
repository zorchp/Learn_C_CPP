#include <list>
#include <iostream>
using namespace std;

template <class T>
ostream& operator<<(ostream& os, const list<T>& l) {
    for (auto& i : l) os << i << " ";
    return os << endl;
}

void t1() {
    list<int> l1{1, 2, 3, 4, 5};
    list<int> l2;
    // 从一个 list 转移到另一个, 默认是全部转移
    l2.splice(l2.begin(), l1);
    cout << "l1: " << l1; // 空
    cout << "l2: " << l2; // 1 2 3 4 5
}

void t2() {
    list<int> l1{1, 2, 3, 4, 5};
    list<int> l2;
    l2.splice(l2.begin(), l1, next(l1.begin(), 2), l1.end());
    cout << "l1: " << l1;
    cout << "l2: " << l2;
    // l1: 1 2
    // l2: 3 4 5
}

void t3() {
    list<int> l1{1, 2, 3, 4, 5};
    list<int> l2;
    l2.splice(l2.begin(), l1, next(l1.begin(), 2));
    cout << "l1: " << l1;
    cout << "l2: " << l2;
    // l1: 1 2 4 5
    // l2: 3
}

int main(int argc, char* argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}
