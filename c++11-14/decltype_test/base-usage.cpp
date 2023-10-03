#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x = 0;
    int y = 0;
};

Point pt;
Point* pPt = &pt;
const Point* cpPt = &pt;
Point& lrPt = pt;
Point&& rrPt = {};

void t1() {
    cout << typeid(decltype((pt))).name() << endl;
    cout << typeid(decltype((pPt))).name() << endl;
}

int main(int argc, char* argv[]) {
    t1();
    return 0;
}
