#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    goto FLAG;
    cout << 1 << endl;
FLAG:
    cout << 2 << endl;
    return 0;
}