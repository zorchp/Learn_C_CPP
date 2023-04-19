#include <iostream>
using namespace std;

// template <typename T>
// void swap(T* a, T* b) {
//     auto tmp = a;
//     a = b;
//     b = tmp;
// }
void t1() {
    int a = 10, b = 20;
    cout << a << " " << b << endl;
    int *p1 = &a, *p2 = &b;
    // ::swap(*p1, *p2); // 可以交换
    // ::swap(p1, p2); // 不可交换
    // ::swap(**&p1, **&p2); // 可交换
    // ::swap(*&p1, *&p2); // 不可交换
    swap(&p1, &p2); // error
    cout << a << " " << b << endl;
}


int main(int argc, char const* argv[]) {
    t1();
    return 0;
}