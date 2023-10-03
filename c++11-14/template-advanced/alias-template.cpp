#include <bits/stdc++.h>
using namespace std;
const long SIZE = 200;

template <typename T>
using Vec = std::vector<T, allocator<T>>;
void t1() { Vec<int> V1; }

template <typename T>
void output_ststic_data(const T& obj) {
    cout << obj << endl;
}


template <typename Container>
void test_moveable(Container c) {
    typedef typename iterator_traits<typename Container::iterator>::value_type
        Valtype;

    for (long i = 0; i < SIZE; i++) c.insert(c.end(), Valtype("abcd"));
    output_ststic_data(*(c.begin()));
    Container c1(c);       // copy
    Container c2(move(c)); // move copy
    c1.swap(c2);
}

struct MyStr {
    MyStr(const string& s1) : s(s1) {}
    string s;
};
ostream& operator<<(ostream& os, const MyStr& s2) { return os << s2.s; }

void t2() {
    test_moveable(deque<MyStr>());
    test_moveable(list<string>());
}

int main(int argc, char const* argv[]) {
    // t1();
    t2();

    return 0;
}
