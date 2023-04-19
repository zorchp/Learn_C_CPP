#include <iostream>
#include <list>
using namespace std;
list<int> lst{1, 2, 3, 4};

void t1() {

    auto it = lst.begin();
    cout << *(next(it, 1)) << endl;

    // for (auto it = lst.begin(); distance(it, lst.end()) > 0; ++it)
    // for (auto it = lst.begin(); it != lst.end(); ++it) //
    // for (auto it = lst.begin(); it != lst.end(); advance(it, 1)) //
    // for (auto it = lst.begin(); it != lst.end(); it = next(it, 1)) //
    //     cout << *it << endl;
}

void t2() {
    //
    auto it = lst.begin();
    cout << *it << endl; // 1
    lst.emplace_front(12);
    cout << *it << endl;          // 1,迭代器不变
    cout << *lst.begin() << endl; // 12
}

void t3() {
    //
    auto it = lst.begin();
    cout << *it << endl; // 1
    lst.erase(it);
    cout << *it << endl;          // 1, (事实上已经失效了)
    cout << *lst.begin() << endl; // 2
}

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}