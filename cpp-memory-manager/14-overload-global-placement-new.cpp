#include <iostream>
using namespace std;

class P {
public:
    int a; // 4bytes
    // void* operator new[](size_t size) {
    //     P* p = (P*)malloc(size);
    //     cout << "P::new[], size=" << size << endl;
    //     return p;
    // }
    // virtual
    // ~P() {}
};

void* operator new(size_t size, void* start, int flag) {
    cout << "operator new(size_t size, void* start, int flag), size=" << size
         << ", start=" << start << ", flag=" << flag << endl;
    return start;
}

// error: redefinition of 'void* operator new(size_t, void*)'
// void* operator new(size_t size, void* start) {
//     cout << "operator new(size_t size, void* start), size=" << size
//          << ", start=" << start << endl;
//     return start;
// }

void t1() {
    P p0;
    P* p1 = ::new (&p0) P;
    // P* p2 = ::new (&p0, 1) P;
}

int main(int argc, char const* argv[]) {
    // t1();
    return 0;
}