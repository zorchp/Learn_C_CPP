#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int i = 1;
    string s = "a";
    map<int, string> mp;
    mp[i] = s;
    // [=, i]() mutable {
    // [=, i] mutable {
    // [=, &i]() {
    [=]() mutable { // 外部的 i 不会改变, 仅变内部拷贝出来的变量
        cout << mp.size() << endl;
        mp.insert({0, ""});
        i++;
    }();
    cout << mp.size() << endl;
    cout << i << endl;
    return 0;
}
