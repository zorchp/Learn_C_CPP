#include <iostream>
#include <unordered_map>
using namespace std;

int main(int argc, char const* argv[]) {
    unordered_map<int, int> cnt{{1, 2}, {2, 0}};
    if (cnt.count(1)) cout << "cnt[1]\n";
    if (cnt.count(2)) cout << "cnt[2]\n";
    if (cnt.count(22)) cout << "cnt[22]\n";
    cout << "cnt.count(1)=" << cnt.count(1) << endl;      // 1
    cout << "cnt.count(2)=" << cnt.count(2) << endl;      // 1
    cout << "cnt.count(22)=" << cnt.count(22) << endl;    // 1
    cout << unordered_map<int, int>::size_type() << endl; // 0
    return 0;
}
// cnt.count(1)=1
// cnt.count(2)=1
// cnt.count(22)=0
