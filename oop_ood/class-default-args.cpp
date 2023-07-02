#include <string>
#include <cstdio>
class P {
public:
    // P() { printf("%d\n", x); }
    int x{10};
    std::string s{"sss"};
};

int main(int argc, char const *argv[]) {
    printf("%d\n", P().x);
    printf("%s\n", P().s.c_str());
    return 0;
}