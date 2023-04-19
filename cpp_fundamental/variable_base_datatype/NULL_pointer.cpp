#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    // int *p = NULL;
    // *p = 1000;
    int a = 10, *p = &a;
    if (p != nullptr) cout << "nullptr" << endl;
    return 0;
}