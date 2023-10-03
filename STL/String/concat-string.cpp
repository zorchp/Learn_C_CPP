#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

void t1() {
    string s1 =
        "abc"
        "ac"; // ok
    cout << s1 << endl;
    // string s2 = 'a' 'b'; // error
}
int main(int argc, char *argv[]) {
    t1();
    return 0;
}
