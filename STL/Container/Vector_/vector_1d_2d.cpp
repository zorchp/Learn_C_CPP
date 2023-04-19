#include <iostream>
#include <vector>

using namespace std;

// 定义遍历(输出)一维数组的函数
void print1d(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it < v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// 定义遍历二维数组的函数
void print2d(vector<vector<int>> &v) {
    for (vector<vector<int>>::iterator it = v.begin(); it < v.end(); ++it) {
        for (vector<int>::iterator vit = (*it).begin(); vit < (*it).end();
             ++vit) {
            cout << *vit << " ";
        }
        cout << endl;
    }
}

void vector_1d() {
    // 1. 初始化一维大小为10的向量
    vector<int> v1(10);
    // 遍历
    print1d(v1);
    // 向量元素默认全为0
    // 0 0 0 0 0 0 0 0 0 0

    // 2. 给定初始值, 10个2
    vector<int> v2(10, 2);
    print1d(v2);
    // 2 2 2 2 2 2 2 2 2 2

    // 3. 直接给定数据:C++11新标准, 下面两种写法均可
    vector<int> v3{1, 2, 3, 4, 5};
    // vector<int> v3 = {1,2,3,4,5};
    print1d(v3);
    // 1 2 3 4 5

    // 4. 通过数组首地址初始化, 需要有一个定义好的数组
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> v4(arr, arr + 3);
    print1d(v4);
    // 1 2 3

    // 5. 拷贝构造函数
    // 5.1 直接拷贝
    vector<int> v5_1(v1);
    print1d(v5_1);
    // 0 0 0 0 0 0 0 0 0 0

    // 5.2 左闭右开区间元素拷贝给容器本身
    vector<int> v5_2(v1.begin() + 1, v1.end() - 1);
    print1d(v5_2);
    // 0 0 0 0 0 0 0 0
}

void vector_2d() {
    // 1. 直接初始化, 赋值时可采用向二维数组中添加一维数组的方法
    int row = 3, col = 4;
    // 生成一个3行4列的二维向量, 默认元素值均为0
    vector<vector<int>> v1(row, vector<int>(col));
    print2d(v1);
    /*
    0 0 0 0
    0 0 0 0
    0 0 0 0
    */

    // 2. 初始化并赋初值(初始化的向量值全为指定值)
    vector<vector<int>> v2(row, vector<int>(col, 1));
    print2d(v2);
    /*
    1 1 1 1
    1 1 1 1
    1 1 1 1
    */

    // 3. 使用resize()方法指定数组大小,
    // 这里生成一个行数等于列数的二维数组(下三角阵)
    vector<vector<int>> v3;
    v3.resize(row);
    for (int k = 0; k < row; ++k) v3[k].resize(k + 1); //每行为k+1列
    print2d(v3);
    /*
    0
    0 0
    0 0 0
    */

    // 4. C++11特性, 直接赋初值
    vector<vector<int>> v4{{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5}};
    print2d(v4);
    /*
    1 2 3 4
    2 3 4 5
    3 4 5
    */
}

int main(int argc, char const *argv[]) {
    // vector_1d();
    vector_2d();
    return 0;
}