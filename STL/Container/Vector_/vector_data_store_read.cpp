#include <iostream>
#include <vector>

using namespace std;

/*
C++ vector 数据存储和读取
*/

void test1() {
    // 尾插法插入元素
    vector<int> v;
    for (int i = 0; i < 5; i++) { v.push_back(i * 2 + 1); }

    // 1. 利用重载的[] 遍历打印vector中每一元素
    for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
    cout << endl;
    // 1 3 5 7 9

    // 2. 利用at()函数进行遍历(访问元素)
    for (int i = 0; i < v.size(); ++i) { cout << v.at(i) << " "; }
    cout << endl;
    // 1 3 5 7 9

    // 3. 返回第一个元素和最后一个元素
    cout << "front: " << v.front() << "  back: " << v.back() << endl;
    // front: 1  back: 9
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}