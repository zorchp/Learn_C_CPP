#include <string>
#include <iostream>
using namespace std;
class HasPtr {
public:
    HasPtr(const std::string &s = ""s) : ps(new std::string(s)), i(0) {
        cout << __func__ << '\n';
    }
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) {
        cout << __func__ << " copy " << '\n';
    }
    HasPtr &operator=(const HasPtr &rhs) {
        cout << __func__ << '\n';
        auto newp = new string(*rhs.ps);
        delete ps;
        ps = newp;
        i = rhs.i;
        return *this;
    }
    ~HasPtr() {
        cout << __func__ << '\n';
        delete ps;
    }

private:
    std::string *ps;
    int i;
};


void t1() {
    HasPtr p1 = "abc"s;
    HasPtr p2(p1);  // copy ctor
    HasPtr p3 = p1; // copy ctor
    HasPtr p4;      // p4 已经构造了
    p4 = p1;        // copy assignment
    // HasPtr
    // HasPtr copy
    // HasPtr copy
    // HasPtr
    // operator=
    // ~HasPtr
    // ~HasPtr
    // ~HasPtr
    // ~HasPtr
}


int main(int argc, char *argv[]) {
    t1();
    return 0;
}
