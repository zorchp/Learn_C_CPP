#include <bits/stdc++.h>
using namespace std;

std::string_view getBar() {
    std::string b{"it is bar."};
    return b;
}

std::string_view getFoo() { return "It is foo."; }

int main(int argc, char *argv[]) {

    using namespace std::string_literals;
    using namespace std::string_view_literals;
    std::cout << getFoo() << std::endl; // 1
    std::cout << getBar() << std::endl; // 2
    std::string_view svf{"Hello foo"s};
    std::cout << svf << std::endl; // 3
    std::string_view svff{"Hello foo"sv};
    std::cout << svff << std::endl; // 4
    return 0;
}
