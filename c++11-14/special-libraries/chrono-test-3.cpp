#include <iostream>
#include <chrono>
using namespace std;
int main() {
    cout << "system clock          : ";
    cout << chrono::system_clock::period::num << "/"
         << chrono::system_clock::period::den << "s" << endl;
    cout << "steady clock          : ";
    cout << chrono::steady_clock::period::num << "/"
         << chrono::steady_clock::period::den << "s" << endl;
    cout << "high resolution clock : ";
    cout << chrono::high_resolution_clock::period::num << "/"
         << chrono::high_resolution_clock::period::den << "s" << endl;
    /*
    system clock          : 1/1000000000s
    steady clock          : 1/1000000000s
    high resolution clock : 1/1000000000s*/
    return 0;
}