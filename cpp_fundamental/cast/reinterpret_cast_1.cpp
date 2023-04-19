#include <cassert>
#include <cstdint>
#include <iostream>

int f() { return 42; }

void t1() {
    int i = 7;

    // pointer to integer and back
    std::uintptr_t v1 =
        reinterpret_cast<std::uintptr_t>(&i); // static_cast is an error
    std::cout << "The value of &i is " << std::showbase << std::hex << v1
              << '\n';
    int* p1 = reinterpret_cast<int*>(v1);
    assert(p1 == &i);

    // pointer to function to another and back
    void (*fp1)() = reinterpret_cast<void (*)()>(f);
    // fp1(); undefined behavior
    int (*fp2)() = reinterpret_cast<int (*)()>(fp1);
    std::cout << std::dec << fp2() << '\n'; // safe

    // type aliasing through pointer
    char* p2 = reinterpret_cast<char*>(&i);
    std::cout << (p2[0] == '\x7' ? "This system is little-endian\n"
                                 : "This system is big-endian\n");

    // type aliasing through reference
    reinterpret_cast<unsigned int&>(i) = 42;
    std::cout << i << '\n';

    [[maybe_unused]] const int& const_iref = i;
    // int &iref = reinterpret_cast<int&>(
    //     const_iref); // compiler error - can't get rid of const
    // Must use const_cast instead: int &iref = const_cast<int&>(const_iref);
}
/*
The value of &i is 0x16f3b708c
42
This system is little-endian
42
*/


void t2() {
    int a    = 0x00636261;
    int* pi  = &a;
    char* ps = reinterpret_cast<char*>(pi);
    printf("pi=%p, ps=%p\n", pi, ps);
    printf("*pi=%d, ps=%s\n", *pi, ps);
    /*
    pi=0x16d49308c, ps=0x16d49308c
    *pi=6513249, ps=abc
    */
}

void t3() {
    int a    = 0x0063006261;
    int* pi  = &a;
    char* ps = reinterpret_cast<char*>(pi);
    printf("pi=%p, ps=%p\n", pi, ps);
    printf("*pi=%d, ps=%s\n", *pi, ps);
    /*
    pi=0x16f00708c, ps=0x16f00708c
    *pi=1660969569, ps=ab
    */
}

void t4() {
    int a    = 0x64636261;
    int* pi  = &a;
    char* ps = reinterpret_cast<char*>(pi);
    printf("pi=%p, ps=%p\n", pi, ps);
    printf("*pi=%d, ps=%s\n", *pi, ps);
    /*
    pi=0x16b97f08c, ps=0x16b97f08c
    *pi=1684234849, ps=abcd��k//多出的字符是pi被转换成的字符
    */
}

int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}