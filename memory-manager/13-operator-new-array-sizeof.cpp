#include <iostream>
using namespace std;

class P {
public:
    // P() = default;
    int a; // 4bytes
    void* operator new(size_t size) {
        P* p = (P*)malloc(size);
        cout << "P::new, size=" << size << endl;
        return p;
    }
    void* operator new[](size_t size) {
        P* p = (P*)malloc(size);
        cout << "P::new[], size=" << size << endl;
        return p;
    }
    virtual ~P() {}
};


void t1() {
    cout << sizeof(size_t) << endl;               // 8
    cout << sizeof(long) << endl;                 // 8
    cout << sizeof(unsigned long) << endl;        // 8
    cout << sizeof(unsigned) << endl;             // 4
    cout << typeid(unsigned).name() << endl;      // j
    cout << typeid(unsigned int).name() << endl;  // j
    cout << typeid(unsigned long).name() << endl; // m
    cout << typeid(size_t).name() << endl;        // m
}
void t2() {
    P* p = new P;
    cout << sizeof(*p) << endl;
    // 4 (无析构函数)
    // 4 (无虚析构, 仅有析构)
    // 16 (虚析构)
    delete p;
}
void t3() {
    P* p1 = new P[5]();
    // 20 (无析构函数) 因为没设置析构函数,
    // 这时候就不会记录之后delete时候要释放的大小, 所以没有size_t信息,
    // 也就只有4*5=20大小 28 (无虚析构, 仅有析构) 88 (虚析构)
    delete[] p1;
}
int main(int argc, char const* argv[]) {
    t2();
    t3();
    return 0;
}