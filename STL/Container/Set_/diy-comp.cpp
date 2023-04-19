#include <vector>
#include <iostream>
#include <functional>
#include <set>
#include <algorithm>

using namespace std;

void t1() {
    using B = pair<int, int>;
    // error
    // function<bool(const B &, const B &)> cmp = [](const B &a, const B &b)
    // {
    auto cmp = [](const B &a, const B &b) { return a.first < b.first; };

    set<B, decltype(cmp)> s2;
    s2.insert({1, 2});
    s2.insert({3, 4});
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}
