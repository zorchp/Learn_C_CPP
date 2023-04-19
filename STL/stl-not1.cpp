#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

struct LessThan7 : std::unary_function<int, bool> {
    bool operator()(int i) const { return i < 7; }
};

int main() {
    std::vector<int> v(10);
    std::iota(begin(v), end(v), 0);

    std::cout << std::count_if(begin(v), end(v), std::not1(LessThan7()))
              << "\n";

    // same as above, but using `std::function`
    std::function<bool(int)> less_than_9 = [](int x) { return x < 9; };
    std::cout << std::count_if(begin(v), end(v), std::not1(less_than_9))
              << "\n";
}
