#include <bits/stdc++.h>
using namespace std;

void t1() {
    ifstream ifs("cin-1.cpp");
    if (!ifs.is_open()) {
        cout << "failed\n";
    }
    string s;
    getline(ifs, s);
    cout << s;
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
