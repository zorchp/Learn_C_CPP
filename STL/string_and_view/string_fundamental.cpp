#include <algorithm>
#include <iostream>
#include <string>
#include <typeinfo>
#include <charconv>

using namespace std;

void t1() {
    // char const *s;
    string s;
    s = "abc132";
    // cout<<s[s.size()-1]<<endl;
    // int a = 100;
    cout << s << endl;
    reverse(s.begin(), s.end());
    cout << s << endl;
}

void t2() {
    string s1{};
    s1.push_back('2');
    s1.append("abcde", 5);
    s1 = "ios"
         "bac";
    cout << s1 << endl;
}
void t3() {
    string s1{"123"};
    string s2;
    s2 = "abc" + s1;
    cout << s2 << endl;
}
void t4() {
    std::string str = "TheBigStr";
    std::string_view p1 = std::string_view(str.data() + 3, 3);
    cout << p1 << endl;
    string p2 = static_cast<std::string>(p1);
    p2 += str;
    cout << p2 << endl;
}

void t5() {
    cout << stoi("123") << endl;
    cout << stoi("2.123") << endl;
    char s[10] = {'3', '.', '1', '4', '\0'};
    double val{};
    from_chars(s, s + 4, val);
    cout << val << endl;
    string s2{"0.618"};
    from_chars(s2.data(), s2.data() + s2.size(), val);
    cout << val << endl;
    /*123
    2
    3.14
    0.618*/
}

/* void t6() { */
/*     auto u1 = u8"\228"; */
/*     // cout << typeid(u1).name() << endl; */
/*     cout << *u1 << endl; */
/* } */

void t7() {
    string s1 = "abcd";
    cout << (s1.find("dww") == string::npos) << endl;
}

void t8() {
    string s1 = "abcdef";
    cout << s1.substr(1, 2) << endl;
}
int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    // t3();
    // t4();
    // t5();
    // t6();
    // t7();
    t8();
    return 0;
}
