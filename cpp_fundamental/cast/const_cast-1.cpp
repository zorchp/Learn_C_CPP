#include <iostream>

using namespace std;


void t1() {
    const char* cp;
    char* p = const_cast<char*>(cp);
    char* q = (char*)"123";
    p = q;
    cout << p << endl;
    cout << q << endl;
}

const string& cmp(const string& s1, const string& s2) {
    cout << "const cmp" << endl;
    return s1.size() <= s2.size() ? s1 : s2;
}

string& cmp(string& s1, string& s2) {
    auto& r = cmp(const_cast<const string&>(s1), const_cast<const string&>(s2));
    cout << "using const_cast cmp" << endl;
    return const_cast<string&>(r);
}

void t2() {
    const string s1{"123"}, s2{"12"};
    cout << cmp(s1, s2) << endl;
}

void t3() {
    string s3{"123"}, s4{"12"};
    string ret_const = cmp(s3, s4); //此时直接赋值为非常量,可以修改
    // auto ret_const = cmp(s3, s4); // 此时也可以修改
    // const string ret_const = cmp(s3, s4); // 此时不能修改
    cout << ret_const << endl;
    ret_const = string("234");
    cout << ret_const << endl;
    /*
    const cmp
    using const_cast cmp
    12
    234
    */
}

int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    t3();

    return 0;
}