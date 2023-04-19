#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int N = 5;
    int *pa = new int[N]();
    // C++11新标准
    // 可以事先给定初值
    // 用于初始化列表
    int *pb = new int[N]{1, 2, 3, 4, 5};

    for (int i = 0; i < N; ++i) {
        cout << *(pa + i) << "  ";
    }
    cout << endl;

    for (int i = 0; i < N; ++i) {
        cout << *(pb + i) << "  ";
    }
    cout << endl;

    delete[] pa;
    delete[] pb;
    return 0;
}
