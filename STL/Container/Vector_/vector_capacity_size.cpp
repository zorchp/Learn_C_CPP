#include <iostream>
#include <vector>

using namespace std;

void printV(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it < v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void test1() {
    // 初始化向量并赋初值(尾插)
    vector<int> v1;
    for (int i = 0; i < 5; i++) { v1.push_back(i * 2 + 1); }
    // 遍历
    printV(v1);

    if (v1.empty()) {
        cout << "empty" << endl;
    } else {
        cout << "not empty" << endl;
        cout << "capacity: " << v1.capacity() << endl;
        cout << "size: " << v1.size() << endl;
    }

    // resize()函数重新指定容器的大小
    // 可以使用重载的版本指定变大size后需要向数组中填充的值
    v1.resize(10, 333);
    printV(v1);
    cout << "capacity: " << v1.capacity() << endl;
    cout << "size: " << v1.size() << endl;

    v1.resize(5);
    cout << "capacity: " << v1.capacity() << endl;
    cout << "size: " << v1.size() << endl;
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}