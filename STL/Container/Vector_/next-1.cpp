#include <iostream>
#include <iterator>
#include <vector>

void t1() {
    std::vector<int> v{4, 5, 6};

    auto it = v.begin();
    auto nx = std::next(it, 2);
    std::cout << *it << ' ' << *nx << '\n';

    it = v.end();
    nx = std::next(it, -2);
    std::cout << ' ' << *nx << '\n';
}
/*
4 6
 5
*/

void t2() {
    std::vector<int> v{4, 5, 6};

    auto it = v.begin();
    std::advance(it, 2);
    std::cout << *it << '\n';

    it = v.end();
    std::advance(it, -2);
    std::cout << *it << '\n';
    // 6
    // 5
}

int main(int argc, char const *argv[]) {
    t1();
    t2();
    return 0;
}