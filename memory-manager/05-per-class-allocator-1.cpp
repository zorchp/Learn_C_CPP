#include <cstddef>
#include <iostream>
using namespace std;

namespace jj04 {
// ref. C++Primer 3/e, p.765
// per-class allocator

class Screen {
public:
    Screen(int x) : i(x){};
    int get() { return i; }

    void* operator new(size_t);
    void operator delete(void*, size_t); //(2)
    // void operator delete(void*);         //(1) 二擇一.
    //! 若(1)(2)並存,會有很奇怪的報錯 (摸不著頭緒)
    // link error

private:
    Screen* next;
    static Screen* freeStore; // 指向链表头部
    static const int screenChunk;

private:
    int i;
};
Screen* Screen::freeStore = nullptr; // 空指针
const int Screen::screenChunk = 24;

void* Screen::operator new(size_t size) {
    Screen* p;
    if (!freeStore) {
        // linked list 是空的，所以攫取一大塊 memory
        // 以下呼叫的是 global operator new
        size_t chunk = screenChunk * size;
        freeStore = p = reinterpret_cast<Screen*>(new char[chunk]);
        // 將分配得來的一大塊 memory 當做 linked list 般小塊小塊串接起來
        for (; p != &freeStore[screenChunk - 1]; ++p) p->next = p + 1;
        p->next = nullptr;
    }
    p = freeStore;
    freeStore = freeStore->next;
    return p;
}


//! void Screen::operator delete(void *p)       //(1)
void Screen::operator delete(void* p, size_t) { //(2)二擇一
    // 將 deleted object(delete一次仅有一个区块被收集起来) 收回插入 free list
    // 前端(首结点)
    (static_cast<Screen*>(p))->next = freeStore; // next指向freeStore头部
    freeStore = static_cast<Screen*>(p);         // freeStore回到头部
}

//-------------
void test_per_class_allocator_1() {
    cout << "\ntest_per_class_allocator_1().......... \n";

    cout << sizeof(Screen) << endl; // 8

    size_t const N = 100;
    Screen* p[N];

    for (int i = 0; i < N; ++i) p[i] = new Screen(i);

    // 輸出前 10 個 pointers, 用以比較其間隔
    for (int i = 0; i < 10; ++i) cout << p[i] << endl;

    for (int i = 0; i < N; ++i) delete p[i];
}
} // namespace jj04

int main(int argc, char const* argv[]) {
    cout << __cplusplus << endl;

    jj04::test_per_class_allocator_1();
    /*
    202002

    test_per_class_allocator_1()..........
    16
    0x13ef04080
    0x13ef04090
    0x13ef040a0
    0x13ef040b0
    0x13ef040c0
    0x13ef040d0
    0x13ef040e0
    0x13ef040f0
    0x13ef04100
    0x13ef04110
    */

    // using system operator new and delete void
    /*
    202002

    test_per_class_allocator_1()..........
    16
    0x600000a3c040
    0x600000a3c050
    0x600000a3c060
    0x600000a3c070
    0x600000a3c080
    0x600000a3c090
    0x600000a3c0a0
    0x600000a3c0b0
    0x600000a3c0c0
    0x600000a3c0d0
    */

    return 0;
}