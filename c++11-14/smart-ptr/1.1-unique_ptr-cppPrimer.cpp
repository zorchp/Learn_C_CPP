#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

void t1() {
    // init unique_ptr
    unique_ptr<int> p1;
    unique_ptr<double> p2(new double(1.2));
    // unique_ptr拥有其所指向的对象, 所以不支持拷贝操作
    unique_ptr<string> p3(new string("12"));
    // unique_ptr<string> p4(p3);//error
    unique_ptr<string> p5;
    // p5=p3;//error
}
void t11() {
    unique_ptr<string> p1(new string("1"));
    p1.reset();
    cout << p1 << endl;
    unique_ptr<string> p2(new string("2"));
    p2.reset(nullptr);
    cout << p2 << endl;
    /*0x0
    0x0*/
}
void t12() {
    auto u1 = make_unique<int>(1);
    cout << typeid(u1).name() << endl;
    // NSt3__110unique_ptrIiNS_14default_deleteIiEEEE
}

void t2() { // use release() and reset()
    // u.release() 放弃对指针的控制权, 返回指针u, 并将指针u置为空
    // release()返回的指针通常被用来初始化另一个智能指针或给另一个智能指针赋值
    // =============================================================
    // u.reset() 释放指针u指向的对象, 若函数带有参数(内置指针,记为q),
    // 则令u释放之后指向指针q指向的对象, 将所有权从p1转移给p2
    unique_ptr<string> p1(new string("hello"));
    unique_ptr<string> p2(p1.release()); // 同时, release将p1置空
    cout << "p1=" << p1 << endl;         // p1=0x0
    cout << "nullptr==p1: " << (nullptr == p1) << endl;
    // cout << "*p1=" << *p1 << endl;//segfault
    cout << "*p2=" << *p2 << endl;
    /*
    nullptr==p1: 1
    *p2=hello
    */
    unique_ptr<string> p3(new string("world"));
    p2.reset(p3.release()); // 将所有权从p3转移给p2
    cout << "*p2=" << *p2 << endl;
    cout << "p3==nullptr: " << (p3 == nullptr) << endl;
    /*
    *p2=world
    p3==nullptr: 1
    */
    // p2.release(); // 内存泄漏, p2不会释放内存(但是系统会释放),
    // 同时指针指向的内存丢失 最好写成下面这样:
    auto p = p2.release(); // 此时指针不是智能指针,所以需要在程序最后`delete p;`
    cout << p << endl; // 0x6000023b5120
    delete p;
}

unique_ptr<int> clone(int p) { return unique_ptr<int>(new int(p)); }

unique_ptr<int> clone1(int p) {
    unique_ptr<int> ret(new int(p));
    return ret;
}

void t3() { /*pass value and return unique_ptr*/
    // cout << clone(12) << endl;
    cout << *clone(12) << endl;
    // cout << clone1(121) << endl;
    cout << *clone1(121) << endl;
    /*//为什么地址一样呢?,clang++ OK, g++ error
    0x60000352c040
    12
    0x60000352c040
    121
    */
}

struct destination {};

struct connection {};

connection connect(destination *d1) {
    connection c1;
    return c1;
}
void disconnect(connection *c1) { cout << "deleting..." << endl; }
void end_connection(connection *p) { disconnect(p); }

void t4_deleter(destination &d) {
    // 需要提供一个指定类型的可调用对象:
    //  unique_ptr<objT, delT>  p(new objT, fcn);
    connection c = connect(&d);
    unique_ptr<connection,decltype(end_connection)*>/*此处添加`*`,使其为指针类型*/ p(&c,
                              end_connection); //通过传入自定义的`析构函数`释放内存
}


int main(int argc, char const *argv[]) {
    // t1();
    // t11();
    t12();
    // t2();
    // t3();
    // destination d;
    // t4_deleter(d);
    return 0;
}