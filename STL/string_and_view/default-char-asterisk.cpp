#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;

void t1() {
    auto s1 = "abc";
    cout << typeid(s1).name() << endl; // PKc
}
void t2() {
    auto s2 = "bcd"s; // 字符串字面量C++11
    cout << typeid(s2).name() << endl;
    string s3 = "bcd";
    cout << typeid(s3).name() << endl;
    /*NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
    NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE*/
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}
