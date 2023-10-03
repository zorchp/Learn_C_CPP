#include <bits/stdc++.h>
using namespace std;

void t1() {
    int i;    // undefined val, default i=1 in func
    int j{};  // j=0
    int* p;   // undefined ptr
    int* q{}; // q=nullptr
    cout << "i=" << i << endl;
    cout << "j=" << j << endl;
    cout << "p=" << p << endl;
    cout << "q=" << q << endl;
    /*
    i=1
    j=0
    p=0x0
    q=0x0
     */
}
void t2() {
    int x1(5.3);
    int x2 = 5.3;

    // narrowed
    //  int x3{5.4};
    //  int x4 = {5.4};
    char c1{4};
    // char c2{99999};
    std::vector<int> v1{1, 2, 3};
    // std::vector<int> v2{1, 2, 3.};
}

int main(int argc, char const* argv[]) {
    // t1();
    t2();
    return 0;
}
