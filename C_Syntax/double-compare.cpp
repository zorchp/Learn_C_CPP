#include <iostream>
#include <thread>
using namespace std;
int main(int argc, char *argv[]) {
    double d1 = .1, d2 = .5;
    while (d1 != d2) {
        d1 += .1;
        cout << d1 << endl;
        this_thread::sleep_for(1s);
    }
    return 0;
}
