#include <iostream>
#include <vector>
using namespace std;

template <typename T>
typename T::value_type top(const T& c) {
    if (!c.empty())
        return c.back();
    else
        return typename T::value_type();
}

void t1() {
    vector<int> v1{1, 2, 3, 4, 5}, v2{};
    cout << top(v1) << endl; // 5
    cout << top(v2) << endl; // 0
}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}