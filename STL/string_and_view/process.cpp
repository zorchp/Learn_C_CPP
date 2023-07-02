#include <unistd.h>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    string str{R"(-\|/-)"s};
    int n{100};
    while (n--) {
        // 微秒
        usleep(200 * 1000);
        cout << str[n % 4] << " process:" << 100 - n << "%\r" << flush;
    }
    return 0;
}
