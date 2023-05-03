#include <climits>
#include <iostream>
using namespace std;

void t1() {
    cout << INT_MAX << endl;
    cout << INT32_MAX << endl;
    cout << INT_MIN << endl;
    cout << INT32_MIN << endl;
    /*
    2147483647
    2147483647
    -2147483648
    -2147483648
    */
}

void t2() {
    cout << INT64_MAX << endl;
    cout << INT64_MIN << endl;
    /*
    9223372036854775807
    -9223372036854775808
    */
}
int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}
