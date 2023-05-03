#include <iostream>
using namespace std;

void t1() {
    string str{};
    while (getline(cin, str, ',')) { //
        cout << str << " ";
    }
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}
