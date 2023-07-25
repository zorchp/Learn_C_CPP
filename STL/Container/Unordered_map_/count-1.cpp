#include <cstdio>
#include <iostream>
#include <unordered_map>


int main(int argc, char *argv[]) {
    std::unordered_map<int, int> cnt;
    ++cnt[5];
    --cnt[5];
    std::cout << cnt.count(5) << std::endl; // 1
    printf("%d", cnt[5]);                   // 0
    return 0;
}
