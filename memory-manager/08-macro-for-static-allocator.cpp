#include <complex>
#include <iostream>
using namespace std;

namespace jj10 {

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
    const int CHUNK = 5; //小一點方便觀察
};

void* allocator::allocate(size_t size) {
    obj* p;

    if (!freeStore) {
        // linked list 是空的，所以攫取一大塊 memory
        size_t chunk = CHUNK * size;
        freeStore = p = (obj*) malloc(chunk); //主要通过malloc分配

        // cout << "empty. malloc: " << chunk << "  " << p << endl;

        //將分配得來的一大塊當做 linked list 般小塊小塊串接起來
        for (int i = 0; i < (CHUNK - 1); ++i) { //沒寫很漂亮, 不是重點無所謂.
            p->next = (obj*) ((char*) p + size);
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
    //將 deleted object 收回插入 free list 前端
    ((obj*) p)->next = freeStore;
    freeStore = (obj*) p;
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

//借鏡 MFC macros.
// DECLARE_POOL_ALLOC -- used in class definition
#define DECLARE_POOL_ALLOC()                                           \
public:                                                                \
    void* operator new(size_t size) { return myAlloc.allocate(size); } \
    void operator delete(void* p) { myAlloc.deallocate(p, 0); }        \
                                                                       \
protected:                                                             \
    static allocator myAlloc;

// IMPLEMENT_POOL_ALLOC -- used in class implementation file
#define IMPLEMENT_POOL_ALLOC(class_name) allocator class_name::myAlloc;


// in class definition file
class Foo {
    DECLARE_POOL_ALLOC()
public:
    long L;
    string str;

public:
    Foo(long l) : L(l) {}
};
// in class implementation file
IMPLEMENT_POOL_ALLOC(Foo)


//  in class definition file
class Goo {
    DECLARE_POOL_ALLOC()
public:
    complex<double> c;
    string str;

public:
    Goo(const complex<double>& x) : c(x) {}
};
// in class implementation file
IMPLEMENT_POOL_ALLOC(Goo)


void test_macros_for_static_allocator() {
    cout << "\n\n\ntest_macro_for_static_allocator().......... \n";

    Foo* pF[100];
    Goo* pG[100];

    cout << "sizeof(Foo)= " << sizeof(Foo) << endl;
    cout << "sizeof(Goo)= " << sizeof(Goo) << endl;

    for (int i = 0; i < 23; ++i) { // 23,任意數, 隨意看看結果
        pF[i] = new Foo(i);
        pG[i] = new Goo(complex<double>(i, i));
        cout << pF[i] << ' ' << pF[i]->L << "\t";
        cout << pG[i] << ' ' << pG[i]->c << "\n";
    }

    for (int i = 0; i < 23; ++i) {
        delete pF[i];
        delete pG[i];
    }
}
} // namespace jj10

int main(int argc, char const* argv[]) {
    jj10::test_macros_for_static_allocator();
    /*
    test_macro_for_static_allocator()..........
    sizeof(Foo)= 40
    sizeof(Goo)= 48
    0x600000a44000 0    0x600000e44000 (0,0)
    0x600000a44028 1    0x600000e44030 (1,1)
    0x600000a44050 2    0x600000e44060 (2,2)
    0x600000a44078 3    0x600000e44090 (3,3)
    0x600000a440a0 4    0x600000e440c0 (4,4)
    0x600000a440d0 5    0x600000e440f0 (5,5)
    0x600000a440f8 6    0x600000e44120 (6,6)
    0x600000a44120 7    0x600000e44150 (7,7)
    0x600000a44148 8    0x600000e44180 (8,8)
    0x600000a44170 9    0x600000e441b0 (9,9)
    0x600000a441a0 10   0x600000e441e0 (10,10)
    0x600000a441c8 11   0x600000e44210 (11,11)
    0x600000a441f0 12   0x600000e44240 (12,12)
    0x600000a44218 13   0x600000e44270 (13,13)
    0x600000a44240 14   0x600000e442a0 (14,14)
    0x600000a44270 15   0x600000e442d0 (15,15)
    0x600000a44298 16   0x600000e44300 (16,16)
    0x600000a442c0 17   0x600000e44330 (17,17)
    0x600000a442e8 18   0x600000e44360 (18,18)
    0x600000a44310 19   0x600000e44390 (19,19)
    0x600000a44340 20   0x600000e443c0 (20,20)
    0x600000a44368 21   0x600000e443f0 (21,21)
    0x600000a44390 22   0x600000e44420 (22,22)
    */
    return 0;
}