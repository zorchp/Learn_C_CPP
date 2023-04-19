#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

void t1() {
    auto a = "123"s;
    auto b = "12.3"s;
    cout << stoi(a) << endl;
    cout << stod(b) << endl;
    /* 123 */
    /* 12.3 */
}


int main(int argc, char *argv[]) {
    t1();
    return 0;
}
