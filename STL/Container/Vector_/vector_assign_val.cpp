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
    vector<int> v1;
    for (int i = 0; i < 5; i++) { v1.push_back(i * 2 + 1); }
    printV(v1);

    // 1. 直接赋值
    vector<int> v2;
    v2 = v1;
    printV(v2);

    // 2. assign()函数赋值
    vector<int> v3;
    v3.assign(v1.begin() + 2, v1.end());
    printV(v3);

    // 3. n个elem, assign()函数的重载版本
    vector<int> v4;
    v4.assign(20, 3);
    printV(v4);
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}