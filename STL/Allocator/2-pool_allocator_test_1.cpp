#include <ext/pool_allocator.h> //only on g++
#include <iostream>
#include <vector>

using namespace std;


template <typename Alloc>
void cookie_test(Alloc alloc, size_t n) {
    typename Alloc::value_type *p1, *p2, *p3;
    p1 = alloc.allocate(n);
    p2 = alloc.allocate(n);
    p3 = alloc.allocate(n);
    cout << "p1=" << p1 << endl;
    cout << "p2=" << p2 << endl;
    cout << "p3=" << p3 << endl;
    alloc.deallocate(p1, sizeof(typename Alloc::value_type));
    alloc.deallocate(p2, sizeof(typename Alloc::value_type));
    alloc.deallocate(p3, sizeof(typename Alloc::value_type));
}


void t1() { //使用额外提供的__pool_alloc:
    cout << sizeof(__gnu_cxx::__pool_alloc<int>) << endl; // 1
    vector<int, __gnu_cxx::__pool_alloc<int>> vecPool;
    cookie_test(__gnu_cxx::__pool_alloc<double>(), 1); //相距08h表示不带cookie
    /*
    1
    p1=0x135f04080
    p2=0x135f04088
    p3=0x135f04090
    */
}

void t2() { //使用标准库提供的分配器
    cout << sizeof(allocator<int>) << endl;
    vector<int, allocator<int>> vec;
    cookie_test(allocator<double>(), 1); //相距10h表示带有cookie
    /*
    1
p1=0x600002a84040
p2=0x600002a84050
p3=0x600002a84060
*/
}

int main(int argc, char const *argv[]) {
    t1();
    t2();
    return 0;
}