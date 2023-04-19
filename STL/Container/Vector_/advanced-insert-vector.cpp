#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;
ostream& operator<<(ostream& os, const vector<int>& v) {
    for (int i : v) os << i << " ";
    return os << endl;
}
void t1() {
    vector<int> v1{1, 2}, v2{3, 4, 5};
    vector<int> v3(10);
    // cout << v1;
    // cout << v3;
    // v3.insert(v3.begin() + 1, v1.begin(), v1.end());
    // v3.insert(v3.begin() + 3, v2.begin(), v2.end());
    cout << v3;
}
int main(int argc, char const* argv[]) {
    t1();
    return 0;
}