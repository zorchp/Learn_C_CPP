#include <iostream>
using namespace std;
struct Copyable {
    Copyable() {}
    Copyable(const Copyable &o) { cout << "Copied" << endl; }
};
Copyable ReturnRvalue() { return Copyable(); }
void AcceptVal(Copyable) {}
void AcceptRef(const Copyable &) {}
int main() {
    cout << "Pass by value: " << endl;
    AcceptVal(ReturnRvalue()); // 临时值被拷贝传入
    cout << "Pass by reference: " << endl;
    AcceptRef(ReturnRvalue()); // 临时值被作为引用传递
}
// 编译选项:g++ 3-3-5.cpp -fno-elide-constructors
/* :!g++ 3-20-const-ref-reduce-consume.cpp -fno-elide-constructors -std=c++11
 * &&./a.out */
/* Pass by value: */
/* Copied */
/* Copied */
/* Pass by reference: */
/* Copied */
