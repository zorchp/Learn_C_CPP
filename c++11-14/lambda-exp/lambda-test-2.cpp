#include <bits/stdc++.h>
using namespace std;


void t1() {
    int id  = 0, param{};
    auto f1 = [&id](int param) {
        cout << "id: " << id << endl;
        cout << "param: " << param << endl;

        ++id;
        ++param;
    };
    id = 42;
    f1(7);
    f1(7);
    f1(7);
    cout << "id: " << id << endl;
}

void t2() {
    int id1 = 0;
    auto f2 = [id1]() mutable {
        cout << "id1: " << id1 << endl;
        ++id1;
    };
    id1 = 42;
    f2();
    f2();
    f2();
    cout << "id1: " << id1 << endl;
}

void t3() {
    int id2 = 0;
    auto f3 = [id2]() {
        cout << "id2: " << id2 << endl;
        // ++id2;
    };
    id2 = 42;
    f3();
    f3();
    f3();
    cout << "id2: " << id2 << endl;
}
int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    // t3();//error
    return 0;
}