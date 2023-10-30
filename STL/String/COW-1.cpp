#include <bits/stdc++.h>
using namespace std;


void t1() {
    string x = "abc";
    string y = x; // copy
    cout << hex << &x << endl;
    cout << hex << &y << endl;
    string tmp = "def";
    y += tmp;
    cout << hex << &x << endl;
    cout << hex << &y << endl;
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
