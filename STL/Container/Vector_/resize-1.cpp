#include <vector>
#include <iostream>

using namespace std;


ostream& operator<<(ostream& os, const vector<int>& v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}

void t1() {
    vector v = {1, 2, 3, 4, 5};
    v.reserve(9);
    cout << v.size() << endl;     // 5
    cout << v.capacity() << endl; // 9
    // 如果已经有值了, 就不会利用第二参数初始化,
    // 比当前的 size 小, 直接减为当前 resize 指定的大小
    // 但是不改变 capacity
    v.resize(3, 1);
    cout << v; // 1 2 3

    cout << v.size() << endl;     // 3
    cout << v.capacity() << endl; // 9
    v.resize(6, 2);
    cout << v; // 1 2 3 2 2 2

    cout << v.size() << endl;     // 6
    cout << v.capacity() << endl; // 9
}

void t2() {
    // 如果是开始初始化就会用第二参数初始化
    vector<int> v;
    v.reserve(10);
    cout << v.size() << endl;     // 0
    cout << v.capacity() << endl; // 10
    v.emplace_back(0);
    // v[1] = 23;
    v.resize(3, 1);
    cout << v;
    cout << v.size() << endl;     // 3
    cout << v.capacity() << endl; // 10
}

// 总结, resize 第二参数的 作用只发生在未初始化的元素中

void t3() {
    vector<int> v{1, 2, 3};
    v.reserve(5);
    cout << v.size() << endl;     // 3
    cout << v.capacity() << endl; // 5
    v.resize(6, 3); // 比当前的 capacity 大了, 也会触发 2 倍扩容机制
    cout << v.size() << endl;     // 6
    cout << v.capacity() << endl; // 10
    cout << v;                    // 1 2 3 3 3 3
}

int main(int argc, char* argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}
