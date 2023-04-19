#include <iostream>
#include <memory>
#include <string>
#include <typeinfo>
#include <vector>
/*
智能指针陷阱:
1. 不使用相同的内置指针初始化(或reset)多个智能指针
2. 不delete get() 返回的指针
3. 不使用get()初始化或reset另一个智能指针
4. 如果使用get()返回的指针, 当最后一个对应的智能指针被销毁后,指针将变为悬空
5. 使用智能指针(而非new), 需要传递给他一个删除器.
*/

using namespace std;

void t1() {
    shared_ptr<int> p1;
    shared_ptr<int> p2(new int(42));
    cout << p1 << " " << p2 << endl;
    cout << *p2 << endl;
/*0 0x600000f94040
42*/}

void t2() {
    // initialize shared_ptr with `new`:
    // shared_ptr<int> p1 = new int(10); // error,must use explicit init
    shared_ptr<int> p2(new int(10));
    cout << p2 << " " << *p2 << endl; // 0x6000039d0040 10
}

void process(shared_ptr<int> ptr) { // use ptr
} // ptr离开作用域, 被销毁
void t3() {
    // do not use both ptr and smart ptr:
    shared_ptr<int> p(new int(10)); // ref cnt=1
    process(p);                     // ref cnt=2
    int i = *p;                     // ref cnt=1
}

void t4() {
    int *x(new int(1024));
    // process(x);
    /* error: could not convert 'x' from 'int*' to 'std::shared_ptr<int>'*/
    process(shared_ptr<int>(
        x)); // ok, but memery be released,临时变量被销毁,引用计数已经为0
    int j = *x;
    cout << j << endl; // random value.
}
/*
当将一个智能指针类型绑定到一个普通指针上时候,
我们就将内存的管理责任交给了智能指针.
此时不应该再用内置指针访问智能指针所指向的内存了*/

void t5() {
    // do not use `.get()` init another shared_ptr
    shared_ptr<int> p(new int(42)); // refcnt=1
    cout << hex << p << endl;       // 0x600000e08040

    // p.get()用于返回p中保存的指针, 小心使用, 若智能指针释放了其对象,
    // 返回的指针所指向的对象也消失了
    int *q = p.get();                   // 裸指针
    cout << "*q=" << dec << *q << endl; // 42
    {                         // 两个独立的shared_ptr指向相同的内存
        shared_ptr<int> r(q); // 这块书上错了, 少了r
    } // 作用域结束, q和q指向的内存都被销毁,导致p指向的内存已经被释放了,
      // p成为悬空指针
    // 并且p被销毁时, 同一块内存会被二次delete(由于智能指针的引用计数=0)
    int foo = *p;
    cout << hex << foo << endl; // c9498040, 随机值(dangling ptr)
    cout << hex << p << endl;   // 0x600000e08040
    // -371670976 0x60000299c040
    // 2.1-shared_ptr-with-new.out(68203,0x1032b4580) malloc: *** error for
    // object 0x60000299c040: pointer being freed was not allocated
    // 2.1-shared_ptr-with-new.out(68203,0x1032b4580) malloc: *** set a
    // breakpoint in malloc_error_break to debug zsh: abort
}

void t6() {
    // use reset()
    shared_ptr<int> p;
    cout << typeid(p).name() << endl; // St10shared_ptrIiE
    // p=new int(102); // 不能将指针赋予shared_ptr
    p.reset(new int(102));            // 智能指针p指向新的对象
    cout << typeid(p).name() << endl; // St10shared_ptrIiE

    // reset还会更新引用计数.
    if (!p.unique()) { // 不是唯一的用户, 就分配一份新的拷贝
        p.reset(new int(*p));
    }
    *p += 10;
    cout << p << " " << *p << endl; // 112
}

struct destination {};

struct connection {};

connection connect(destination *d1) {
  connection c1;
  return c1;
}
void disconnect(connection* c1) { cout<<"deleting..."<<endl;}
// void end_connection(connection *p) { disconnect(p); }

void t7(destination &d) {
    connection c = connect(&d);
    shared_ptr<connection> p(&c,
                              [](connection*p){disconnect(p);}); 
                              //通过传入自定义的`析构函数`释放内存
}

int main(int argc, char const *argv[]) {
  // t1();
  // t2();
  // t3();
  // t4();
  t5();
  // t6();
  // destination d;
  // t7(d);
  return 0;
}
