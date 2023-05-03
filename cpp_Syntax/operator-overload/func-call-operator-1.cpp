#include <iostream>

using namespace std;

auto lmd1 = [](const string &s1, const string &s2) {
    return s1.size() < s2.size();
};

class cmp1 {
public:
    bool operator()(const string &s1, const string &s2) const {
        return s1.size() < s2.size();
    }
};

void t1() {
    cout << lmd1("abc", "de") << endl;
    cout << cmp1()("abc", "de") << endl;
}


class cmp2 {
public:
    cmp2(size_t n) : sz(n) {}
    bool operator()(const string &s) const { return s.size() >= sz; }

private:
    size_t sz;
};

void t2() {
    size_t sz = 10;
    auto lmd2 = [sz](const string &s) { return s.size() >= sz; };

    cout << lmd2("12") << endl;
    cout << cmp2(sz)("12") << endl;
}
int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}