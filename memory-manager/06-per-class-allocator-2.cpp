// #include <cstddef>//size_t
#include <iostream>
using namespace std;

namespace jj05 {
// ref. Effective C++ 2e, item10
// per-class allocator

class Airplane { //支援 customized memory management
private:
    struct AirplaneRep {
        unsigned long miles;
        char type;
    };

private:
    union { //采用embedded ptr, 时间错位使得 内存使用降低
        AirplaneRep rep; //此針對 used object, 分配内存时候使用, delete时候不用
        Airplane*
            next; //此針對 free list, 仅在delete时候释放内存时候使用(操作链表)
    };

public:
    unsigned long getMiles() { return rep.miles; }
    char getType() { return rep.type; }
    void set(unsigned long m, char t) {
        rep.miles = m;
        rep.type  = t;
    }

public:
    static void* operator new(size_t size);
    static void operator delete(void* deadObject, size_t size);

private:
    static const int BLOCK_SIZE;
    static Airplane* headOfFreeList;
};

Airplane* Airplane::headOfFreeList;
const int Airplane::BLOCK_SIZE = 512;

void* Airplane::operator new(size_t size) {
    //如果大小錯誤，轉交給 ::operator new()
    //继承则会出现不一致的情况
    if (size != sizeof(Airplane)) return ::operator new(size);

    Airplane* p = headOfFreeList;

    //如果 p 有效，就把list頭部移往下一個元素
    if (p)
        headOfFreeList = p->next;
    else {
        // free list 已空。配置一塊夠大記憶體，
        //令足夠容納 BLOCK_SIZE 個 Airplanes
        Airplane* newBlock = static_cast<Airplane*>(
            ::operator new(BLOCK_SIZE * sizeof(Airplane)));
        //組成一個新的 free list：將小區塊串在一起，但跳過
        //#0 元素，因為要將它傳回給呼叫者。
        for (int i = 1; i < BLOCK_SIZE - 1; ++i)
            newBlock[i].next = &newBlock[i + 1];
        newBlock[BLOCK_SIZE - 1].next = 0; //以null結束

        // 將 p 設至頭部，將 headOfFreeList 設至
        // 下一個可被運用的小區塊。
        p              = newBlock;
        headOfFreeList = &newBlock[1];
    }
    return p;
}

// operator delete 接獲一塊記憶體。
// 如果它的大小正確，就把它加到 free list 的前端
void Airplane::operator delete(void* deadObject, size_t size) {
    if (deadObject == 0) return;
    if (size != sizeof(Airplane)) {
        ::operator delete(deadObject);
        return;
    }

    Airplane* carcass = static_cast<Airplane*>(deadObject);

    carcass->next  = headOfFreeList;
    headOfFreeList = carcass;
    /*如果加上针对分配内存的峰值内存管理就更好了*/
}

//-------------
void test_per_class_allocator_2() {
    cout << "\ntest_per_class_allocator_2().......... \n";

    cout << sizeof(Airplane) << endl; // 8

    size_t const N = 100;
    Airplane* p[N];

    for (int i = 0; i < N; ++i) p[i] = new Airplane;


    //隨機測試 object 正常否
    p[1]->set(1000, 'A');
    p[5]->set(2000, 'B');
    p[9]->set(500000, 'C');
    cout << p[1] << ' ' << p[1]->getType() << ' ' << p[1]->getMiles() << endl;
    cout << p[5] << ' ' << p[5]->getType() << ' ' << p[5]->getMiles() << endl;
    cout << p[9] << ' ' << p[9]->getType() << ' ' << p[9]->getMiles() << endl;

    //輸出前 10 個 pointers, 用以比較其間隔
    for (int i = 0; i < 10; ++i) cout << p[i] << endl;

    for (int i = 0; i < N; ++i) delete p[i];
}
} // namespace jj05


int main(int argc, char const* argv[]) {
    jj05::test_per_class_allocator_2();
    /*
    test_per_class_allocator_2()..........
    16
    0x135009210 A 1000
    0x135009250 B 2000
    0x135009290 C 500000
    0x135009200
    0x135009210
    0x135009220
    0x135009230
    0x135009240
    0x135009250
    0x135009260
    0x135009270
    0x135009280
    0x135009290
    Press ENTER to exit!
    */

    // with system operator new
    /*
    test_per_class_allocator_2()..........
    16
    0x6000002a0050 A 1000
    0x6000002a0090 B 2000
    0x6000002a00d0 C 500000
    0x6000002a0040
    0x6000002a0050
    0x6000002a0060
    0x6000002a0070
    0x6000002a0080
    0x6000002a0090
    0x6000002a00a0
    0x6000002a00b0
    0x6000002a00c0
    0x6000002a00d0
    */
    return 0;
}