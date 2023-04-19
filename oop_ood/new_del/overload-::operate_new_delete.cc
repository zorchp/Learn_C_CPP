#include <iostream>


using namespace std;

//不能被同时声明于一个namespace中
// error: 'void* pp01::operator new(size_t)' may not be declared within a
// namespace namespace pp01 {


void* myAlloc(size_t size) { return malloc(size); }

void myFree(void* ptr) { free(ptr); }

inline void* operator new(size_t size) {
    cout << "global new()" << endl;
    return myAlloc(size);
}


inline void* operator new[](size_t size) {
    cout << "global new[]()" << endl;
    return myAlloc(size);
}

inline void operator delete(void* ptr) {
    cout << "global delete()" << endl;
    myFree(ptr);
}
inline void operator delete(void* ptr, size_t) { // size_t:optional
    cout << "global delete()" << endl;
    myFree(ptr);
}
inline void operator delete[](void* ptr, size_t) { // size_t:optional
    cout << "global delete[]()" << endl;
    myFree(ptr);
}
// } // pp01

void test1() {}

void test2() {}

int main(int argc, char const* argv[]) {
    test1();
    // test2();
    return 0;
}