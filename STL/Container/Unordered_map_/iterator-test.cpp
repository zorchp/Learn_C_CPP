#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;


void t1() {
    unordered_map<string, unordered_set<string>> ans{};
    ans["a"].insert("b");
    ans["a"].insert("c");
    ans["b"].insert("b");
    for (auto it = ans.begin(); it != ans.end(); ++it)
        cout << (*it).first << " " << (*it).second.size() << endl;
    for (auto &[k, v] : ans) cout << k << " " << v.size() << endl;
}

void t2() {
    unordered_set<string> us1{"a", "b", "C"};
    vector<string> v1;
    v1.assign(us1.begin(), us1.end());
    for (auto s : v1) cout << s << endl;
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}