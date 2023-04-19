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
    // 尾插法插入元素
    vector<int> v;
    for (int i = 0; i < 5; i++) { v.push_back(i * 2 + 1); }
    // 遍历vector
    printV(v);
    // 1 3 5 7 9
    v.erase(v.begin());
    printV(v);

    // // 尾部删除元素(尾删)
    // v.pop_back();
    // printV(v);
    // // 1 3 5 7

    // // 指定元素插入, 第一个参数需要传入迭代器(指向pos位置)
    // v.insert(v.begin(), 10);
    // printV(v);
    // // 10 1 3 5 7

    // // 指定元素插入, 传入迭代器, 插入count个elem元素
    // v.insert(v.begin() + 1, 3, 9);
    // printV(v);
    // // 10 9 9 9 1 3 5 7

    // // 删除迭代器指向的元素
    // v.erase(v.end() - 1);
    // printV(v);
    // // 10 9 9 9 1 3 5

    // // 删除区间(左闭右开区间)的元素
    // v.erase(v.begin(), v.end() - 2);
    // printV(v);
    // 3 5
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}