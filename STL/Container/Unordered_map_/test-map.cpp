#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

void t1() {
    unordered_map<string, string> dict = {{"a", "d"}, {"b", "c"}};
    cout << dict.size() << endl;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T> v) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); it++)
        os << *it << (it < v.end() - 1 ? ", " : "]");
    os << endl;
    return os;
}
void t2() {
    unordered_map<int, vector<int>> dd;
    vector<vector<int>> ans;
    dd[1] = {1, 2};
    dd[3].push_back(3); //可以直接赋值
    // if (dd[2].empty()) {
    //     cout << "dd[2] is empty" << endl;
    //     dd[2] = {3, 4};
    // }
    // auto it = dd.begin();
    // cout << (*it).first << (*it).second << endl;
    // cout << dd.size() << endl;
    for (auto it = dd.begin(); it != dd.end(); it++) {
        cout << (*it).first << ": " << (*it).second;
    }
    // or equal:
    for (auto& [k, v] : dd) { cout << k << ": " << v; }
    /*
    3: [3]
    1: [1, 2]
    3: [3]
    1: [1, 2]
    */
}

int main(int argc, char const* argv[]) {
    // t1();
    t2();
    return 0;
}
