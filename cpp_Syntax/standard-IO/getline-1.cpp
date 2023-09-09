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

void t4() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string t;
    int a;
    ss >> t;
    ss >> a;
    cout << "t=" << t << endl;
    cout << "a=" << a << endl;
    // abc 12
    // t=abc
    // a=12
}
void t5() {
    int a, b;
    cin >> a >> b;
    cin.ignore();
    vector<pair<string, int>> aa;
    for (int i{}; i < 3; ++i) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string t;
        int a;
        ss >> t;
        ss >> a;
        aa.emplace_back(t, a);
    }
    for (auto [a, b] : aa) {
        cout << a << " " << b << endl;
    }
}

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    // t3();
    // t4();
    t5();
    return 0;
}
