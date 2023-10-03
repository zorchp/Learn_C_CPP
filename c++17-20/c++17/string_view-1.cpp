#include <iostream>
#include <string>
#include <string_view>


using namespace std;

void t1() {
    string s = "abc";
    string_view ss = s;
    cout << ss[0] << endl;
    s[0] = '1';
    // ss[0] = '2'; // error
    cout << ss << endl;
}

void t2() {
    auto sv = "abcs"sv; // string_view literal
    // s[0] = '4'; // error
    auto s = string(sv);
    s[0] = '2';
    cout << s << endl;
    cout << sv << endl;
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
