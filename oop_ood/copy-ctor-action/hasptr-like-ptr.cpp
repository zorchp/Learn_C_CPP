#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

class HasPtr {
public:
    HasPtr(const std::string &s = ""s)
        : ps(new std::string(s)), i(0), use(new size_t(1)) {
        cout << __func__ << '\n';
    }
    HasPtr(const HasPtr &rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use) {
        ++*use;
        cout << __func__ << " copy " << '\n';
    }
    HasPtr &operator=(const HasPtr &rhs) {
        ++*rhs.use; // 右侧对象引用计数递增
        if (--*use == 0) del_res();
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;

        cout << __func__ << '\n';
        return *this;
    }
    ~HasPtr() {
        if (--*use == 0) {
            del_res();
        }
    }

private:
    void del_res() {
        cout << __func__ << '\n';
        delete ps;
        delete use;
    }
    std::string *ps;
    int i;
    size_t *use; // ref-cnt
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
}


int main(int argc, char *argv[]) {
    t1();
    return 0;
}
