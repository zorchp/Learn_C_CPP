#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename C>
bool lastGreaterThanFirst(const C &container) {
    if (container.empty()) return false;
    typename C::const_iterator begin(container.begin()), end(container.end());
    return *--end > *begin;
}

void t1() {
    vector<int> v{1, 3, 5};
    cout << lastGreaterThanFirst(v); // 1
    reverse(v.begin(), v.end());
    cout << lastGreaterThanFirst(v);
}
int main(int argc, char *argv[]) {
    t1();
    return 0;
}
