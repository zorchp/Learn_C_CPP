#include <iostream>
#include <unordered_map>
using namespace std;

void t1() {
    unordered_map<int, int> m1{};
    for (auto &i : {1, 2, 3, 1}) m1[i]++;
    // cout << "m1[4]=" << m1[4] << endl;
    cout << "m1.count(4)=" << m1.count(4) << endl;
    for (auto &[k, v] : m1) cout << k << " : " << v << endl;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}
/*
m1[4]=0
m1.count(4)=1
4 : 0
3 : 1
2 : 1
1 : 2
*/