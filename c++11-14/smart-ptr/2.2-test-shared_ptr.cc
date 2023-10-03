#include <iostream>
#include <memory>
using namespace std;
void t1() {
    int* p1 = new int(100);
    int* p2 = new int(200);
    p1 = p2;
    cout << p1 << " " << *p1 << endl;
    cout << p2 << " " << *p2 << endl;
    /*
    0x600003684050 200
0x600003684050 200*/
}

void t2() {
    auto p1 = make_shared<int>(100);
    // auto p2 = p1;
    auto p2(p1);
    cout << p1 << " " << *p1 << " " << p1.use_count() << endl;
    cout << p2 << " " << *p2 << " " << p2.use_count() << endl;
    /*0x600003ce5138 200 2
    0x600003ce5138 200 2*/
}

int main(int argc, char const* argv[]) {
    // t1();
    t2();
    return 0;
}