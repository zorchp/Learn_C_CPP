#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    string s = "-------------------------\n";
    int a[]  = {91, 2, 10};
    int *pa  = a;

    // 数组名存放数组首地址
    // 表达式中的数组名与常量指针等效
    // 数组名代表首地址，是常量指针
    cout << "The first address of aray 'a' is : " << endl;
    cout << "a=" << a << endl;
    cout << "&a[0]=" << &a[0] << endl;
    cout << "pa=" << pa << endl;
    cout << "`pa++`=" << pa++ << endl;
    cout << s;

    // 指针指向数组的第一个值
    cout << "The first value of aray 'a' is: " << endl;
    cout << "*pa=" << *pa << endl;
    cout << "*a=" << *a << endl;
    cout << "a[0]=" << a[0] << endl;
    cout << "pa[0]=" << pa[0] << endl;
    cout << s;

    // 取数组的第二个值
    cout << "The second value of aray 'a' is: " << endl;
    cout << "*(pa+1)=" << *(pa + 1) << endl;
    cout << "*(a+1)=" << *(a + 1) << endl;
    cout << "a[1]=" << a[1] << endl;
    cout << "pa[1]=" << pa[1] << endl;
    cout << s;

    // 修改数组某个位置的值
    *(pa + 1) = 10;
    cout << "When we carry out: `*(pa+1)=10`" << endl;
    cout << "a[1]=" << a[1] << endl;
    return 0;
}