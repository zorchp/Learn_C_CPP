#include <cstddef>
#include <iostream>
#include <string>
using namespace std;
class HasPtr {
public:
    HasPtr(const string &s = string())
        : ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) {
        ++*use;
        cout << "after copy ctor, use: " << *use << endl;
    }
    HasPtr &operator=(const HasPtr &);
    HasPtr &operator=(const string &);
    string &operator*() { return *ps; }
    ~HasPtr();
    int get_use_cnt() { return *use; }
    void print() {
        cout << "*ps: " << *ps << ", i: " << i << ", *use: " << *use << endl;
    }

private:
    string *ps;
    int i;
    size_t *use; // 记录有多少对象共享*ps的成员
};

HasPtr::~HasPtr() {
    cout << "before dtor, use: " << *this->use << endl;
    if (--*use == 0) {
        delete ps;
        delete use;
        use = nullptr;
    }
    if (use)
        cout << "after dtor, use: " << *this->use << endl;
    else
        cout << "use deleted..\n";
}

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
    cout << "before copy assignment, this->use: " << *this->use << endl;
    cout << "before copy assignment, rhs.use: " << *rhs.use << endl;
    ++*rhs.use;
    if (--*use == 0) {
        delete ps;
        delete use;
        use = nullptr;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use; // 这一步将右对象的引用计数赋值给左对象,
                   // 使得两个对象共享同一份引用计数
    cout << "after copy assignment, this->use: " << *this->use << endl;
    cout << "after copy assignment, rhs.use: " << *rhs.use << endl;
    return *this;
}

HasPtr &HasPtr::operator=(const string &rhs) {
    *ps = rhs;
    return *this;
}

void t1() {
    //
    cout << "HasPtr h(\"abc\")\n";
    HasPtr h("abc"), h2;
    cout << "h: ";
    h.print();
    cout << "h2: ";
    h2.print();

    /* cout << "\nHasPtr h2 = h;\n"; */
    /* HasPtr h2 = h; */
    /* cout << "h: "; */
    /* h.print(); */
    /* cout << "h2: "; */
    /* h2.print(); */

    /* cout << "\nh = \"cde\"\n"; */
    /* h = "cde"; */
    /* cout << "h: "; */
    /* h.print(); */
    /* cout << "h2: "; */
    /* h2.print(); */

    cout << "\nh = h2;\n";
    h2 = h;
    cout << "h: ";
    h.print();
    /* cout << h.get_use_cnt() << endl; */
    cout << "h2: ";
    h2.print();
    /* cout << h2.get_use_cnt() << endl; */
}

/* HasPtr h("abc") */
/* h: *ps: abc, i: 0, *use: 1 */
/*  */
/* HasPtr h2 = h; */
/* h: *ps: abc, i: 0, *use: 2 */
/* h2: *ps: abc, i: 0, *use: 2 */
/*  */
/* h = "cde" */
/* h: *ps: cde, i: 0, *use: 2 */
/* h2: *ps: cde, i: 0, *use: 2 */
int main(int argc, char *argv[]) {
    t1();
    return 0;
}
