#include <iostream>
using namespace std;

void t1() {
    if (1 == 1 and not 2) {
        cout << "1\n";
    }
%>

class A {
public:
    A() {}
    // compl == ~
    compl A() {}
};

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
