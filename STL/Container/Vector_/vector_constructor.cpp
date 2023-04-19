#include <algorithm>
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
    // 1. 默认构造函数(无参构造)
    vector<int> v1;
    for (int i = 0; i < 5; i++) { v1.push_back(i * 2 + 1); }
    printV(v1);

    // 2. 左闭右开区间元素拷贝给容器本身
    vector<int> v2(v1.begin() + 1, v1.end() - 1);
    printV(v2);

    // 3. 构造函数将n个elem拷贝给容器本身
    vector<int> v3(10, 2);
    printV(v3);

    // 4. 拷贝构造函数
    vector<int> v4(v2);
    printV(v4);
}

void t2() {
    vector<int> v1{1, 2, 3}, v2{4, 5}, v3{};
    v3 = merge(v1, v2);
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}