#include <bits/stdc++.h>
using namespace std;

void t1() {
    // old assign method
    complex<int> c(1, 2);
    int a[] = {1, 2};
}

void t2() {
    // uniform initialization
    int v1[3]{1, 2, 3};
    vector<int> v2{1, 2, 3};
    vector<string> vs{"12", "df"};
    complex<double> c{3.0, 3.0}; // equal to c(3.0,3.0)
}

int main(int argc, char const *argv[]) {
    t1();
    t2();
    return 0;
}
