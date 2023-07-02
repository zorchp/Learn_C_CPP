#include <string_view>
#include <iostream>

using namespace std;

void t1() {
    constexpr std::string_view unicode[]{"▀▄─", "▄▀─", "▀─▄", "▄─▀"};

    for (int y{}, p{}; y != 6; ++y, p = ((p + 1) % 4)) {
        for (int x{}; x != 16; ++x) //
            std::cout << unicode[p];
        std::cout << '\n';
    }
}

std::string_view GetStringView() {
    std::string name = "你好";
    return std::string_view(name); // 离开作用域时，name已经被回收销毁
}

void t2() {
    auto t = GetStringView();
    cout << t; //
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}