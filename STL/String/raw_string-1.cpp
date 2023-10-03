#include <string>
#include <iostream>
using namespace std;


void t1() {
    auto s = R"(D:\Desktop\)";
    cout << s << endl;
}
void t2() {
    // comment not work in raw string
    auto t = R"( // raw string can get newline
        [1,2,3]
    )";
    cout << t << endl;
}

void t3() {
    // with parenthesis :
    auto s = R"#(R"(this is R"(123)"raw string in raw string)")#";
    // use `/` as separator
    cout << s << endl;
}
void t4() {
    auto t = R"(\)";
    cout << t << endl;
}

int main(int argc, char *argv[]) {
    // t1();
    // t2();
    t3();
    // t4();
    return 0;
}
