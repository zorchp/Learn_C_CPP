#include <map>
#include <iostream>
using namespace std;

void t1() {
    map<int, int> mp;
    mp[0] = 1;
    // mp.insert({0, 2});
    if (mp[2])
        cout << "inserted\n";
    else
        cout << "nope\n";
    mp.emplace(0, 2);
    for (auto [k, v] : mp) {
        cout << k << " :" << v << endl;
    }
}
int main(int argc, char *argv[]) {
    t1();
    return 0;
}
