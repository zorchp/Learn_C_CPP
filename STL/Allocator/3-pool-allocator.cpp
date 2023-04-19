#include <ext/pool_allocator.h> //only on g++

#include <iostream>
#include <list>

using namespace std;


static long long countNew = 0;
static long long timesNew = 0;

void* myAlloc(size_t size) { return malloc(size); }

void myFree(void* ptr) { return free(ptr); }

inline void* operator new(size_t size) {
    // cout << "global new(), \t" << size << "\t";

    countNew += size;
    ++timesNew;
    return myAlloc(size);
}

inline void* operator new[](size_t size) {
    cout << "global new[](), \t" << size << "\t";
    return myAlloc(size);
}

inline void operator delete(void* ptr) { myFree(ptr); }
inline void operator delete(void* ptr, size_t size) { myFree(ptr); }
inline void operator delete[](void* ptr) { myFree(ptr); }
inline void operator delete[](void* ptr, size_t size) { myFree(ptr); }


void t1() {
    countNew = 0;
    timesNew = 0;
    list<double> lst;
    for (int i = 0; i < 1000000; ++i) { lst.push_back(i); }
    cout << "::countNew=" << ::countNew << endl;
    cout << "::timesNew=" << ::timesNew << endl;
    /*::countNew=24000000
::timesNew=1000000*/
}


template <typename T>
using listPool = list<T, __gnu_cxx::__pool_alloc<T>>;
void t2() {
    countNew = 0;
    timesNew = 0;
    listPool<double> lst;
    for (int i = 0; i < 1000000; i++) lst.push_back(i);
    cout << "::countNew=" << ::countNew << endl;
    cout << "::timesNew=" << ::timesNew << endl;
    /*::countNew=25087984
::timesNew=122*/
}
int main(int argc, char const* argv[]) {
    // t1();
    t2();
    return 0;
}