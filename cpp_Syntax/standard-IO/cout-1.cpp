#include <iostream>
using namespace std;


void t1() {
    auto s = "abce";
    cout.write(s, 3);
    cout.put('d');
}

void t2() {
    cout << boolalpha;
    cout << true << endl << false << endl;
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
