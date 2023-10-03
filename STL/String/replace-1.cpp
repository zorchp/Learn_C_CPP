#include <bits/stdc++.h>
using namespace std;

void t1() {
    auto s = "abcdef"s;
    cout << s.capacity() << endl;
    s.replace(1, 3, string(28, 'x')); // not safe , no bound check
    cout << s.capacity() << endl;
    cout << s << endl;
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
