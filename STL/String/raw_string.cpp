#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;


void t1() {
    auto str = R"(nier:automata, C:\Desktop)";
    cout << str << endl;
    /* nier:automata, C:\Desktop */
}

void t2() {
    auto s1 = R"==(R"(xxx)")==";
    cout << s1 << endl;
    /* R"(xxx)" */
}

void t3() {
    /* auto s2 = R"(R"()")"s; // error */
    auto s2 = R"&(R"()")&"s; // R"()"
    cout << s2 << endl;
}

void t4() {
    auto s = R"(\)"s;
    cout << s << endl;
}
int main(int argc, char* argv[]) {
    /* t1(); */
    /* t2(); */
    // t3();
    t4();
    return 0;
}
