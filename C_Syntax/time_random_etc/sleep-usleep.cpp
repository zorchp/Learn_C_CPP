#include <unistd.h>
#include <iostream>

using namespace std;

void t1() {
    cout << "begin to sleep\n";
    // sleep(3);
    // equal to
    usleep(3000'000);
    cout << "over\n";
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
