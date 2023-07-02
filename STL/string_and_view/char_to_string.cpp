#include <string>
#include <vector>
#include <iostream>
using namespace std;


void t1() {
    char a = 'a';
    // string s(a);
    string s("a");
    cout << s << endl;
}

void t2() {
    const char* cc = "123dbc";
    // for (auto c : cc) cout << c << " "; // error
    cout << endl;
}


int main(int argc, char const* argv[]) {
    // t1();
    t2();
    return 0;
}