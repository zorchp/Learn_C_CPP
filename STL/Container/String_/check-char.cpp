#include <_ctype.h>
#include <cctype>
#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

void t1() {
    char c1 = 'a';
    cout << islower(c1) << endl; // 1
    char c2 = 'N';
    cout << isupper(c2) << endl; // 1
    char c3 = '0';
    cout << isnumber(c3) << endl; // 1
    char c4 = '0';
    cout << isalnum(c4) << endl; // 1
    char c5 = 'g';
    cout << isxdigit(c5) << endl; // 0
}
void t2() {
    char c1 = 'a';
    /* cout << (char)toupper(c1) << endl; // A */
    cout << static_cast<char>(toupper(c1)) << endl; // A
    char c2 = 'A';
    cout << (char)tolower(c2) << endl; // a
}

int main(int argc, char *argv[]) {
    /* t1(); */
    t2();
    return 0;
}
