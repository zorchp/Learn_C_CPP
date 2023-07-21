#include <vector>
#include <iostream>

using namespace std;


ostream& operator<<(ostream& os, const vector<int>& v) {
    for (auto i : v)
        os << i << " ";
    return os << endl;
}

void t1() {
    vector v = {1, 2, 3, 4, 5};
    v.reserve(9);
    cout << v.size() << endl;     // 5
    cout << v.capacity() << endl; // 9
    v.reserve(4);
    cout << v;
    // no change
    cout << v.size() << endl;     // 5
    cout << v.capacity() << endl; // 9
}

int main(int argc, char* argv[]) {
    t1();
    return 0;
}
