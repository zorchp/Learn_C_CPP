#include <deque>
#include <iostream>
#include <vector>
#include <queue>
void t1() {
    std::vector<bool> vb;
    vb.emplace_back(1);
    std::cout << sizeof(vb) << std::endl; // 40 in gcc, 24 in clang
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
