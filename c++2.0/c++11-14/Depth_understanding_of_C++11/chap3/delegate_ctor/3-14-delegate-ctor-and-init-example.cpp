#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;

class TDConstructed {
private:
    // 构造模板函数, 在下面的两个委派构造函数委托时, 该模板函数被实例化
    // 比罗列多种类型的构造函数方便, 委托构造也使构造函数泛型编程成为可能
    template <class T>
    TDConstructed(T first, T last) : l(first, last) {
        cout << "use template ctor\n";
    }
    list<int> l;

public:
    TDConstructed(vector<short> &v) : TDConstructed(v.begin(), v.end()) {}
    TDConstructed(deque<int> &d) : TDConstructed(d.begin(), d.end()) {}
};

void t1() {
    vector<short> v1;
    TDConstructed t1(v1);

    deque<int> d1;
    TDConstructed t2(d1);
    /* use template ctor */
    /* use template ctor */
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
