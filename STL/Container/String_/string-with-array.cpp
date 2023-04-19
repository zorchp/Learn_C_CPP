#include <bits/stdc++.h>
using namespace std;

void t1() {
    // C 风格的char-array, size=4
    cout << typeid("abc").name() << endl;
    cout << typeid("a").name() << endl;
    cout << typeid('a').name() << endl;
    // ----------------------------------
    cout << typeid(string("abc")).name() << endl;
    cout << typeid(string("a")).name() << endl;
    // cout << typeid(string('a')).name() << endl; //error cannot conversion
    // from char to string

    cout << max({"abb", "bcc", "aaa"}) << endl;
    /*
    A4_c
    A2_c
    c
    NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    aaa
    */
}

void t2() {
    string as[9] = {"123", "acs", "222"};
    cout << typeid(as).name() << endl;
    cout << *(as + 2) << endl;
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}