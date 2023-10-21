#include <map>
#include <iostream>
using namespace std;

void t1() {
    multimap<int, int> mp;
    mp.insert({0, 1});
    mp.emplace(0, 2);
    for (auto [k, v] : mp) {
        cout << k << " :" << v << endl;
    }
}
int main(int argc, char *argv[]) {
    t1();
    return 0;
}
