#include <bits/stdc++.h>
using namespace std;

void process(int& i) { cout << "process(int&): " << i << endl; }

void process(int&& i) { cout << "process(int&&): " << i << endl; }

void forward(int&& i) {
    cout << "forward(int&&): " << i << ", ";
    process(i);
}

void t1() {
    int a = 0;
    process(a);       // a:lval
    process(1);       // 1:rval, temp obj: rval
    process(move(a)); // a: lval->rval
    forward(
        2); // unperfect forwarding,
            // rval->lval,转接过程出问题(丢失了变量的信息,由于a是一个具名变量)
    process(move(a));
    // forward(a);
}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}