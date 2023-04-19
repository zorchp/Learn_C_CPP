#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> v;
    for (int i = 1; i < 10; i++) v.push_back((i * 10));
    std::ostream_iterator<int> out_it(std::cout, ", ");
    // 10, 20, 30, 40, 50, 60, 70, 80, 90,
    std::copy(v.begin(), v.end(), out_it);
    return 0;
}