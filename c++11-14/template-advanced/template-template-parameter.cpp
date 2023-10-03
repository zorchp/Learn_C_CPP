#include <bits/stdc++.h>
using namespace std;
const long SIZE = 200;


template <typename T>
void output_static_data(const T& obj) {
    cout << obj << endl;
}

// alias template
template <typename T>
using Vec = std::vector<T, allocator<T>>;

template <typename T, template <typename U> class Container>
class XCls {
private:
    Container<T> c;

public:
    XCls() { // ctor
        for (long i = 0; i < SIZE; ++i) c.insert(c.end(), T("aa"));
        output_static_data(*(c.begin()));
        Container<T> c1(c);            // copy
        Container<T> c2(std::move(c)); // move copy
        c1.swap(c2);
    }
};

struct MyStr {
    MyStr() = default;
    MyStr(const string& s1) : s(s1) {}
    string s;
};

ostream& operator<<(ostream& os, const MyStr& s2) { return os << s2.s; }


void t1() { XCls<MyStr, Vec> c1; }

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}