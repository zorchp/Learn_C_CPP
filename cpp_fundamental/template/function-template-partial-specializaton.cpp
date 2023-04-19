#include <iostream>
using namespace std;
// 模板函数
template <typename T1, typename T2>
void fun(T1 a, T2 b) {
    cout << "模板函数" << endl;
}
// 全特化
template <>
void fun(int a, char b) {
    cout << "全特化" << endl;
}
// 函数不存在偏特化，以下代码是错误的
/*
template<typename T2>
void fun(char a,T2 b){
    cout<<"偏特化"<<ednl;
}
*/
int main() {
    int a = 0;
    char b='A';
    fun(a,a);
    fun(a,b);
    return 0;
}