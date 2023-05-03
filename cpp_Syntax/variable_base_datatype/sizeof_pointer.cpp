#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int a  = 10;
    int *p = &a;
    cout << sizeof(*p) << endl;
    cout << sizeof(a) << endl;
    cout << "--------------------------" << endl;
    cout << sizeof(int *) << endl;
    cout << sizeof(p) << endl;
    return 0;
}