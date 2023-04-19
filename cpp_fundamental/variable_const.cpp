#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    const int a = 10;
    int b = a; //可以由常量对象给非常量对象初始化
    int c{};
    c = a;
    const int d = b;
    cout << ++b << " " << a << endl;
    const string s1 = "abc";
    string s2 = s1; //可以由常量对象给非常量对象初始化, 但是不能赋值
    cout << s1 << " " << s2 + "bb" << endl;
    return 0;
}
