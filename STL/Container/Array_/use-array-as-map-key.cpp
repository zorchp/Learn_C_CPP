#include <array>
#include <map>


void t1() {
    typedef char my_key_t[8];
    std::map<my_key_t, int> mp;
    my_key_t mykey{"nihao"};
    // mp[mykey] = 5; // error
}

void t2() {
    typedef std::array<char, 8> my_key_t;
    std::map<my_key_t, int> mp;
    my_key_t mykey{"nihao"};
    mp[mykey] = 5; // ok
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
