#include"utils/print-type.h"
#include <complex>
#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {
    // reload cout
    cout << complex<int>(1, 2) << endl; //(1,2)
    return 0;
}
