#include <iostream>
using namespace std;
class Info {
public:
    Info() { InitRest(); }
    Info(int i) {
        new (this) Info();
        type = i;
    }
    Info(char e) {
        new (this) Info();
        name = e;
    }
    /* Info(int i) : type(i) { InitRest(); } */
    /* Info(char e) : name(e) { InitRest(); } */

private:
    void InitRest() { cout << "call InitRest()\n"; }
    int type{1};
    char name{'a'};
    // ...
};
void t1() { Info i1; }

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
