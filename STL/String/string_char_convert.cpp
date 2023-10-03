#include <iostream>
#include <string>
using namespace std;

void t1() {
    char a = 'a';
    string s{};
    s.push_back(a);
    cout << a << endl;
    cout << s << endl;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}
