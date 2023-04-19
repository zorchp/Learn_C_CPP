#include <iostream>
using namespace std;
void ConstTest1() {
    const int a = 1;
    int *p;
    p = const_cast<int *>(&a);
    (*p)++;
    cout << a << endl;  // 1
    cout << *p << endl; // 2
    cout << a << endl;  // 1
}

void ConstTest2() {
    int i = 3;
    const int a = i;
    int &r = const_cast<int &>(a);
    r++;
    cout << i << endl; // 3
    cout << r << endl; // 4
    cout << a << endl; // 4
}
int main() {
    // ConstTest1();
    ConstTest2();
    return 0;
}
