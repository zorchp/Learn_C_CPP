#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::literals;

ostream &operator<<(ostream &os, const vector<int> &v) {
    for (auto i : v) cout << i << " ";
    return os << endl;
}

void t1() {
    vector<int> v{1, 2, 3};
    for (int i{}; i < v.size(); ++i) {
        v.emplace_back(1);
        cout << v;
        cout << v.size() << endl;
        this_thread::sleep_for(1s);
    }
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}