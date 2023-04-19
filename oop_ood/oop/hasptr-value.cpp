#include <iostream>
#include <string>
using namespace std;

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) {}
    HasPtr &operator=(const HasPtr &rhs) {
        auto newp = new string(*rhs.ps);
        delete ps;
        ps = newp;
        i = rhs.i;
        return *this;
    }
    string get() { return *ps; }

private:
    string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout << "swap by myself\n";
}

void t1() {
    HasPtr a("hello");
    HasPtr b;
    b = a;
    HasPtr c = a;
    cout << a.get() << endl;
    cout << b.get() << endl;
    cout << c.get() << endl;
}
/* hello */
/* hello */
/* hello */

void t2() {
    HasPtr a("a"), b("b");
    cout << a.get() << endl;
    cout << b.get() << endl;
    swap(a, b);
    cout << a.get() << endl;
    cout << b.get() << endl;
}
int main(int argc, char *argv[]) {
    /* t1(); */
    t2();
    return 0;
}
