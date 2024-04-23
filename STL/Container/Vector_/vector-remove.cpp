#include <iostream>
#include <vector>

std::ostream &operator<<(std::ostream &os, std::vector<int> &v) {
    for (auto &x : v) {
        os << x << " ";
    }
    return os << std::endl;
}

void t1() {
    std::vector<int> v{1, 2, 1, 3, 1, 4, 1, 1, 2};
    std::cout << v;
    auto it = std::remove(v.begin(), v.end(), 1);
    std::cout << v;
    std::cout << std::distance(v.begin(), it) << std::endl;
    v.erase(it, v.end());
    std::cout << v;
    // 1 2 1 3 1 4 1 1 2
    // 2 3 4 2 1 4 1 1 2
    // 4
    // 2 3 4 2
}

void move2head(std::vector<int> &nums) {
    // move 0 to the first of array
    int n = nums.size();
    int j{n - 1};
    for (int i{n - 1}; i >= 0; --i) {
        if (nums[i] != 0) nums[j--] = nums[i];
    }
    while (~j) nums[j--] = 0; // ~j means j != -1
}

void t2() {
    std::vector<int> v = {0, 2, 3, 1, 0, 1, 0, 2, 0};
    std::cout << v;
    move2head(v);
    std::cout << v;
    // 0 2 3 1 0 1 0 2 0
    // 0 0 0 0 2 3 1 1 2
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
