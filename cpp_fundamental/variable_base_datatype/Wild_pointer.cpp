#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int *p = (int *)0x0010;
    cout << *p << endl;
    return 0;
}