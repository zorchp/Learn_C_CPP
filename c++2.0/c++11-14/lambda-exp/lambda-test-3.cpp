#include "bits/stdc++.h"
using namespace std;


class Person {
public:
    Person(const string &s) : lastname(s) {}
    string lastname;
};

void t1() {
    auto cmp = [](const Person &p1, const Person &p2) {
        return p1.lastname < p2.lastname;
    };
}
int main(int argc, char const *argv[]) {
    t1();
    return 0;
}
