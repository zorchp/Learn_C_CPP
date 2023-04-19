#include <bits/stdc++.h>
using namespace std;


void print(initializer_list<int> vals) {
    for (auto it = vals.begin(); it != vals.end(); it++) {
        cout << *it << endl;
    }
}

void t1() {
    // print(1, 2, 3);// error
    print({1, 2, 3});
}

class P {
public:
    P(int a, int b) { cout << "P(int, int), a=" << a << " b=" << b << endl; }
    // P(initializer_list<int> initlist) {
    //     cout << "P (initializer_list<int>), vals= ";
    //     for (auto i : initlist) { cout << i << " "; }
    //     cout << endl;
    // }

    ~P(){};
};
void t2() {
    P p(55, 3);
    P q{55, 3};
    P r{44, 2, 2};
    P s = {
        2,
        3,
    };
    P t({
        2,
        3,
        4,
    });
    /*
    P(int, int), a=55 b=3
    P (initializer_list<int>), vals= 55 3
    P (initializer_list<int>), vals= 44 2 2
    P (initializer_list<int>), vals= 2 3
    P (initializer_list<int>), vals= 2 3 4
    */
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}