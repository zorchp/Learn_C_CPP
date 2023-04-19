#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// shared_ptr, which allows multiple pointers to refer to the same object

void t1() {
    shared_ptr<string> p1;
    shared_ptr<string> p11 = make_shared<string>("");
    shared_ptr<string> p12 = make_shared<string>("Hello!");
    shared_ptr<list<int>> p2;
    if (!p1) cout << "p1 is nullptr" << endl;

    if (p11 && p11->empty()) {
        cout << "p11 is not nullptr" << endl;
        *p11 = "hi";
    }
    cout << "p11=" << p11 << endl;
    cout << "*p11=" << *p11 << endl;
    /*
    p1 is nullptr
    p11 is not nullptr
    p11=0x600003b64010
    *p11=hi
    */
    cout << "p12=" << p12 << endl;
    cout << "*p12=" << *p12 << endl;
    /*p12=0x600003b68010
     *p12=Hello!*/
}
void t11() {
    shared_ptr<int> sp = make_shared<int>(1);
    int *p1 = sp.get();
    cout << sp << endl;
    cout << p1 << endl;
    delete p1;
    cout << sp << endl; // error, 内存泄漏
    // cout << p1 << endl;
    // auto q(sp);
    // auto p2 = sp.get();
    // cout << sp << endl;
    // cout << p2 << endl;
}

void t2() {
    shared_ptr<int> p3 = make_shared<int>(42);
    shared_ptr<string> p4 = make_shared<string>(10, '2');
    cout << *p3 << endl;
    cout << *p4 << endl;
    /*42
    2222222222*/
    auto p5 = make_shared<vector<int>>();
    p5->push_back(10);
    cout << p5->at(0) << endl; // 10
}

void t3() {
    // shared_ptr: copy and assign
    auto p = make_shared<int>(42); // p指向的对象只有一个引用者p
    auto q(p);                     // p,q指向相同对象,引用计数+1
    // reference-count==0:自动释放内存
    auto r = make_shared<int>(42);
    r = q; // r指向的int被释放
    /*给r赋值,指向另一地址,递增q指向的引用计数, 递减r原来指向的对象的引用计数,
     * r原来指向的int已没有引用者,被自动释放*/
}

class Foo {};
template <typename T>
shared_ptr<Foo> factory(T arg) {
    return make_shared<Foo>(arg);
}

template <typename T>
void use_factory(T arg) {
    shared_ptr<Foo> p = factory(arg);
    // p离开作用域之后,p指向的内存自动销毁
    // return p;//若使用了p, 引用计数+1,p虽然离开scope但是所指内存并不会被释放
}

void t4() {
    vector<string> v1;
    { // begin scope
        vector<string> v2{"12", "23"};
        v1 = v2;
    }                          // v2:destoryed,但是数据还在.
    cout << v1.size() << endl; // 2
    // cout << v2.size() << endl; // error: use of undeclared identifier 'v2'
}

void t5_new_const() {
    const int *pci = new const int(1024);
    const string *pcs = new const string;
    cout << *pci << endl;
    cout << *pcs << endl;
    delete pci;
    delete pcs;
}

void t6_memory_over() {
    int *p1 = new int;
    cout << *p1 << endl; // 0
    int *p2 = new (nothrow) int('0');
    delete p1;
    delete p2;
    int*p=nullptr;
    delete p;//ok
    p=nullptr;
}

int main(int argc, char const *argv[]) {
    // t1();
    // t11();
    // t2();
    // t3();
    t4();
    // t5_new_const();
    // t6_memory_over();
  return 0;
}
