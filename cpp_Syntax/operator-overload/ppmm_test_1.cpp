#include <iostream>
using namespace std;

void print(int *arr) {
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void test() {
    int arr[10], cnt{}; // cnt = 1(default in clang++)
    cout << cnt << endl;
    for (int i = 1; i < 10; ++i) {
        arr[cnt++] = i;
        cout << "cnt: " << cnt << endl;
    }
    print(arr);
    cout << cnt << endl;
    /*g++:segmentation fault*/
    /*clang++
    1
    cnt: 2
    cnt: 3
    cnt: 4
    cnt: 5
    cnt: 6
    cnt: 7
    cnt: 8
    cnt: 9
    cnt: 10
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10
    */
    // with `int cnt{};`
    /*g++
    0
    cnt: 1
    cnt: 2
    cnt: 3
    cnt: 4
    cnt: 5
    cnt: 6
    cnt: 7
    cnt: 8
    cnt: 9
    1, 2, 3, 4, 5, 6, 7, 8, 9, 1,
    9
    */
    /*clang++
    0
    cnt: 1
    cnt: 2
    cnt: 3
    cnt: 4
    cnt: 5
    cnt: 6
    cnt: 7
    cnt: 8
    cnt: 9
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
    9
    */
}

void t1() {
    int a(6);
    ++(++a);           //++++a;
    cout << a << endl; // 8
    // (a++)++;//error: lvalue required as increment operand
    // cout << a << endl;
}

void t2() {
    int aa[10]{}; // with {}: 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    print(aa);
    /*9928816, 1, 5438892, 1, 5488736, 1, 1871524048, 1, 9579380, 1213431809,*/
}

void t3() {
    int a = 10, b = 10;
    int c = a++; // 先赋值(返回原始的值a=10)再自增(变成11)
    int d = ++b; // 先自增(a=11)再赋值(返回自增后的结果11)
    cout << "a=" << a << ", b=" << b << endl;
    cout << "c(a++)=" << c << ", d(++b)=" << d << endl;
    /*
    a=11, b=11
    c(a++)=10, d(++b)=11
    */
}

int main(int argc, char const *argv[]) {
    test();
    // t1();
    // t2();
    // t3();
}
