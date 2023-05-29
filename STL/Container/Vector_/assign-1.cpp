#include <vector>
#include <iostream>
using namespace std;

void t1() {
    vector<int> v;
    for (auto i : {1, 2, 3}) v.insert(v.end(), i, i);
    for (auto i : v) cout << i << endl;
}

int main(int argc, char* argv[]) {
    t1();
    return 0;
}
