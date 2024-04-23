#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<int> a{1, 2, 3};
    // std::reverse(a.rbegin(), a.rend());
    std::reverse(a.begin(), a.end());
    for (auto i : a) {
        std::cout << i << " ";
    }
    return 0;
}
