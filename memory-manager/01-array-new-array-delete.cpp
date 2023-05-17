#include <iostream>
#include <string>
#include <complex>
using namespace std;

void t1() {
    complex<int>* pca = new complex<int>[3]; // 3次ctor
    delete pca; // 3次dtor, 可以不加[], 析构函数没有使用
}
void t2() {
    string* psa = new string[3];
    delete psa; // 必须加上[]
    /*
    1-array-new-array-delete.out(65368,0x104584580) malloc: *** error for object
    0x600002334008: pointer being freed was not allocated
    1-array-new-array-delete.out(65368,0x104584580) malloc: *** set a breakpoint
    in malloc_error_break to debug [1]    65368 abort
    */
}

class A {
public:
    int id;
    A() : id(0) {
        cout << "default ctor. this=" << this << ", id=" << id << endl;
    }
    A(int i) : id(i) { cout << "ctor. this=" << this << ", id=" << id << endl; }
    ~A() { cout << "dtor. this=" << this << ", id=" << id << endl; }
};

void t3() {
    const int size = 3;
    A* buf = new A[size]; // 这一步中A必须有默认构造函数, 否则不会创建成功
    A* tmp = buf;
    cout << "buf=" << buf << ", tmp=" << tmp << endl;

    for (int i = 0; i < size; i++) new (tmp++) A(i); // ctor 3次, placement new
    cout << "buf=" << buf << ", tmp=" << tmp << endl;

    delete[] buf; // 3次dtor,逆序
    /*
    default ctor. this=0x600000d31108, id=0
    default ctor. this=0x600000d3110c, id=0
    default ctor. this=0x600000d31110, id=0
    buf=0x600000d31108, tmp=0x600000d31108
    ctor. this=0x600000d31108, id=0
    ctor. this=0x600000d3110c, id=1
    ctor. this=0x600000d31110, id=2
    buf=0x600000d31108, tmp=0x600000d31114
    dtor. this=0x600000d31110, id=2
    dtor. this=0x600000d3110c, id=1
    dtor. this=0x600000d31108, id=0
    */
}

// cookie
void t4() {
    int* pi = new int[10];
    cout << "sizeof(pi)=" << sizeof(pi) << endl; // 8
    delete pi;                                   // int可不加[]

    int ia[10];
    cout << "sizeof(ia)=" << sizeof(ia) << endl;
    /*
    sizeof(pi)=8
    sizeof(ia)=40
    */
}


class B {
public:
    int id1, id2{}, id3{};
    B() : id1(0) {
        cout << "default ctor. this=" << this << ", id1=" << id1 << endl;
    }
    B(int i) : id1(i) {
        cout << "ctor. this=" << this << ", id1=" << id1 << endl;
    }
    ~B() { cout << "dtor. this=" << this << ", id1=" << id1 << endl; }
};

void t5() {
    B* p = new B[3];
    delete[] p;
    /*
    default ctor. this=0x600003c64278, id1=0
    default ctor. this=0x600003c64284, id1=0
    default ctor. this=0x600003c64290, id1=0
    dtor. this=0x600003c64290, id1=0
    dtor. this=0x600003c64284, id1=0
    dtor. this=0x600003c64278, id1=0
    */
    B b[3];
    cout << sizeof(b) << endl;
    /*
    default ctor. this=0x16dcc7060, id1=0
    default ctor. this=0x16dcc706c, id1=0
    default ctor. this=0x16dcc7078, id1=0
    36
    dtor. this=0x16dcc7078, id1=0
    dtor. this=0x16dcc706c, id1=0
    dtor. this=0x16dcc7060, id1=0
    */
}

int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    // t3();
    // t4();
    t5();
    return 0;
}
