#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


void t1() {
    // vector<string> v1 = {"abc", "def"};
    map<int, int> m1{{1, 2}, {2, 3}};
    for (pair<int, int> a : m1) { cout << a.first << " " << a.second << endl; }
    for (auto& a : m1) { cout << a.first << " " << a.second << endl; }
}


int main(int argc, char const* argv[]) {
    t1();
    return 0;
}