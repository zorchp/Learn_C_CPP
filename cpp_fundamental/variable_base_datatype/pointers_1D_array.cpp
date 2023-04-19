#include <cmath>
#include <iostream>

using namespace std;

// 引用数组元素的四种方式

int main(int argc, char const *argv[]) {
    const int n = 5;
    int a[n]    = {2, 3, 4, 5, 6};

    // 第一种方式
    // 使用数组名与下标
    cout << "The first method is \"array name and subscript\": " << endl;
    for (int i = 0; i < n; ++i) { cout << a[i] << "\t"; }
    cout << endl << endl;

    // 第二种方式
    // 数组名与指针运算
    cout << "The second method is \"array name and pointer operation\": "
         << endl;
    for (int i = 0; i < n; ++i) { cout << *(a + i) << "\t"; }
    cout << endl << endl;


    // 第三种方式
    // 指针与指针运算
    cout << "The third method is \"pointer and pointer operation\": " << endl;
    for (int *pa = a; pa < a + n; ++pa) { cout << *pa << "\t"; }
    cout << endl << endl;


    // 第四种方式
    // 指针与数组运算
    cout << "The fourth method is \"pointer and array operation\": " << endl;
    for (int *pa = a, i = 0; i < n; ++i) { cout << pa[i] << "\t"; }
    return 0;
}