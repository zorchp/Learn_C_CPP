#include <complex>
#include <iostream>
using namespace std;
// version 3
namespace jj09 {

class allocator {
private:
    struct obj {
        struct obj* next; // embedded pointer
    };

public:
    void* allocate(size_t);
    void deallocate(void*, size_t);
    void check();

private:
    obj* freeStore = nullptr;
    const int CHUNK = 5; // 小一點方便觀察
};

void* allocator::allocate(size_t size) {
    obj* p;

    if (!freeStore) {
        // linked list 是空的，所以攫取一大塊 memory
        size_t chunk = CHUNK * size;
        freeStore = p = (obj*)malloc(chunk); // 主要通过malloc分配

        // cout << "empty. malloc: " << chunk << "  " << p << endl;

        // 將分配得來的一大塊當做 linked list 般小塊小塊串接起來
        for (int i = 0; i < (CHUNK - 1); ++i) { // 沒寫很漂亮, 不是重點無所謂.
            p->next = (obj*)((char*)p + size);
            p = p->next;
        }
        p->next = nullptr; // last
    }
    p = freeStore;
    freeStore = freeStore->next;

    // cout << "p= " << p << "  freeStore= " << freeStore << endl;

    return p;
}
void allocator::deallocate(void* p, size_t) {
    // 將 deleted object 收回插入 free list 前端
    ((obj*)p)->next = freeStore;
    freeStore = (obj*)p;
}
void allocator::check() {
    obj* p = freeStore;
    int count = 0;

    while (p) {
        cout << p << endl;
        p = p->next;
        count++;
    }
    cout << count << endl;
}
//--------------

class Foo {
public:
    long L;
    string str;
    static allocator myAlloc;

public:
    Foo(long l) : L(l) {}
    static void* operator new(size_t size) { return myAlloc.allocate(size); }
    static void operator delete(void* pdead, size_t size) {
        return myAlloc.deallocate(pdead, size);
    }
};
allocator Foo::myAlloc;


class Goo {
public:
    complex<double> c;
    string str;
    static allocator myAlloc;

public:
    Goo(const complex<double>& x) : c(x) {}
    static void* operator new(size_t size) { return myAlloc.allocate(size); }
    static void operator delete(void* pdead, size_t size) {
        return myAlloc.deallocate(pdead, size);
    }
};
allocator Goo::myAlloc;

//-------------
void test_static_allocator_3() {
    cout << "\n\n\ntest_static_allocator().......... \n";

    {
        Foo* p[100];

        cout << "sizeof(Foo)= " << sizeof(Foo) << endl;
        for (int i = 0; i < 23; ++i) { // 23,任意數, 隨意看看結果
            p[i] = new Foo(i);
            cout << p[i] << ' ' << p[i]->L << endl;
        }
        // Foo::myAlloc.check();

        for (int i = 0; i < 23; ++i) { delete p[i]; }
        // Foo::myAlloc.check();
    }

    {
        Goo* p[100];

        cout << "sizeof(Goo)= " << sizeof(Goo) << endl;
        for (int i = 0; i < 17; ++i) { // 17,任意數, 隨意看看結果
            p[i] = new Goo(complex<double>(i, i));
            cout << p[i] << ' ' << p[i]->c << endl;
        }
        // Goo::myAlloc.check();

        for (int i = 0; i < 17; ++i) { delete p[i]; }
        // Goo::myAlloc.check();
    }
}
} // namespace jj09

int main(int argc, char const* argv[]) {
    jj09::test_static_allocator_3();
    /*
    test_static_allocator()..........
    sizeof(Foo)= 40
    0x60000158c000 0
    0x60000158c028 1
    0x60000158c050 2
    0x60000158c078 3
    0x60000158c0a0 4//
    0x60000158c0d0 5
    0x60000158c0f8 6
    0x60000158c120 7
    0x60000158c148 8
    0x60000158c170 9//
    0x60000158c1a0 10
    0x60000158c1c8 11
    0x60000158c1f0 12
    0x60000158c218 13
    0x60000158c240 14//
    0x60000158c270 15
    0x60000158c298 16
    0x60000158c2c0 17
    0x60000158c2e8 18
    0x60000158c310 19//
    0x60000158c340 20
    0x60000158c368 21
    0x60000158c390 22
    sizeof(Goo)= 48
    0x60000118c000 (0,0)
    0x60000118c030 (1,1)
    0x60000118c060 (2,2)
    0x60000118c090 (3,3)
    0x60000118c0c0 (4,4)
    0x60000118c0f0 (5,5)
    0x60000118c120 (6,6)
    0x60000118c150 (7,7)
    0x60000118c180 (8,8)
    0x60000118c1b0 (9,9)
    0x60000118c1e0 (10,10)
    0x60000118c210 (11,11)
    0x60000118c240 (12,12)
    0x60000118c270 (13,13)
    0x60000118c2a0 (14,14)
    0x60000118c2d0 (15,15)
    0x60000118c300 (16,16)
    */

    return 0;
}