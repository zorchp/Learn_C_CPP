#include <array>
#include <bitset>
#include <vector>
#include <iostream>
#include <string>

// 存在依赖模板参数构造的对象, 需要加 template 标记
// 当前面存在依赖于模板参数的对象时, 才需要在模板内部使用`.template`
// 标记(或者`->template` 标记), 这些标记仅能在模板中使用
template <int N>
void printBitset(std::bitset<N> const &bs) {
    // method 1
    // std::cout << bs.template to_string<char, std::char_traits<char>,
    //                                    std::allocator<char>>();
    // error method
    // std::cout
    //     << bs.to_string<char, std::char_traits<char>,
    //     std::allocator<char>>();
    // error: use 'template' keyword to treat 'to_string' as a dependent
    // template name
    // method 2
    std::cout << bs.to_string();
}


void t1() {
    std::bitset<12> bs;
    bs[1] = 1;
    printBitset<12>(bs);
}

void t2() {
    //
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
