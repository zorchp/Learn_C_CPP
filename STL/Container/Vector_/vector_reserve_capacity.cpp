#include <iostream>
#include <vector>

using namespace std;


void test1() {
    // 尾插法插入元素
    vector<int> v;
    // 统计内存开辟次数
    int num = 0;
    int *p  = NULL;
    for (int i = 0; i < 10000; i++) {
        v.push_back(i * 2 + 1);

        if (p != &v[0]) {
            p = &v[0];
            num++;
        }
    }
    cout << "内存重新分配的次数: " << num << endl;

    // 尾插法插入元素
    vector<int> v1;

    // 预留空间reserve(), 使内存不会多次分配
    v1.reserve(10000);

    // 统计内存开辟次数
    int num1 = 0;
    int *p1  = NULL;
    for (int i = 0; i < 10000; i++) {
        v1.push_back(i * 2 + 1);

        if (p != &v1[0]) {
            p = &v1[0];
            num1++;
        }
    }
    cout << "利用reserve()预留空间之后, 内存重新分配的次数: " << num1 << endl;
}

/*
 * 内存重新分配的次数: 15
 * 利用reserve()预留空间之后, 内存重新分配的次数: 1
 */

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}