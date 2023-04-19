#include <iostream>
#include <string>
// must with stdc++14
void print_with_zeros(const std::string note, std::string const& s) {
    std::cout << note;
    for (const char c : s) {
        (c ? std::cout << c : std::cout << "₀");
    }
    std::cout << " (size = " << s.size() << ")\n";
}
void t1() {
    using namespace std::string_literals;

    std::string s1 = "abc\0\0def";
    std::string s2 = "abc\0\0def"s;
    print_with_zeros("s1: ", s1);
    print_with_zeros("s2: ", s2);

    std::cout << "abcdef"s.substr(1, 4) << '\n';
    /*
    s1: abc (size = 3)
    s2: abc₀₀def (size = 8)
    bcde
    */
}

void t2() {
    // 使用字符串字面量
    using namespace std;
    /* using namespace std::string_literals; */
    std::cout << std::max(1, 2) << std::endl;
    /* std::cout << std::max({1, 2, 34}) << std::endl; // only clang++ */
    std::cout << std::max({"abc"s, "cde"s, "acc"s}) << std::endl;
    /*
    2
    34
    cde
    */
}


int main() {
    t1();
    t2();
}
