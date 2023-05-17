#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
using namespace std;

void t1() {
    string str{};
    while (getline(cin, str, ',')) { //
        cout << str << " ";
    }
}

void t2() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string t;
    // 单行读取, 空格分隔的字符串
    while (ss >> t) {
        cout << "==>" << t << "<==\n";
    }
    cout << "over...\n";
}

void t3() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    // 另一种写法, 需要注意结尾的空格, 也会被读取
    while (ss) {
        string t;
        ss >> t;
        if (t.empty()) break;
        cout << "==>" << t << "<==\n";
    }
    cout << "over...\n";
}

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}
