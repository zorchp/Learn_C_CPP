#include <iostream>
using namespace std;

int main() {
    float a = 12;
    cout << sizeof(a) << endl;
    int b = *reinterpret_cast<int*>(&a);
    // int b = *static_cast<int*>(&a);
    // error: static_cast from 'float *' to 'int *' is not allowed

    std::cout << b;
    // 4
    // 1094713344
}