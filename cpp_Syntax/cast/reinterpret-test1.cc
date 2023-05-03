#include <iostream>
using namespace std;

int main() {
    float a = 12;
    cout << sizeof(a) << endl;
    int b = *reinterpret_cast<int*>(&a);
    // unsigned int c = 01000001010000000000000000000000;
    // std::cout<<c<<std::endl;

    std::cout << b;
}