#include <iostream>
using namespace std;


class P {
public:
    static void f() {
        // 总结: static method no this ptr, no cv-qualifier to qualify

        // static void f() volatile {
        // Static member function cannot have 'volatile' qualifier
        // static void f() const {
        // Static member function cannot have 'const' qualifier
        //  do sth
    }
    // ~P() const {} //'const' qualifier is not allowed on a destructor
};
