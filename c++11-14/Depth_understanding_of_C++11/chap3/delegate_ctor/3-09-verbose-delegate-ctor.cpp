#include <iostream>
using namespace std;

class Info {
public:
    Info() : type(1), name('a') { InitRest(); }
    Info(int i) : type(i), name('a') { InitRest(); }
    Info(char e) : type(1), name(e) { InitRest(); }

private:
    void InitRest() { cout << "call InitRest()\n"; }
    int type;
    char name;
    // ...
};

void t1() { Info i1; }

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
