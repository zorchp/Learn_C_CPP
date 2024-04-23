#include <iostream>
#include <string_view>
using namespace std;

string cat(string_view sv1, string_view sv2) {
    string res{sv1};
    return res += sv2;
}

void t1() {
    string king{"Harold"};
    auto s1 = cat(king, "William");
    auto s2 = cat(king, king);
    auto s3 = cat("Edward", "Stephen"sv);
    auto s4 = cat("Canute"sv, king);
    auto s5 = cat({&king[0], 2}, "Henry"sv);
    auto s6 = cat({&king[0], 2}, {&king[2], 4});
    cout << king[3] << endl;
    cout << &king[3] << endl;

    cout << s5 << endl;
    cout << s6 << endl;
}

void t2() {
    string s{"abcdef"};
    const char* ptr = &s[3];
    auto x = &s[3]; // char*
    cout << ptr << endl;
    cout << typeid(x).name() << endl; // Pc
}

int main(int argc, char* argv[]) {
    // t1();
    t2();
}
