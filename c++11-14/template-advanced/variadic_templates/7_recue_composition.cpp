#include <complex>
#include <iostream>

using namespace std;


/*
递归复合
*/

template <typename... Values>
class tup;
template <>
class tup<> {};


template <typename Head, typename... Tail>
class tup<Head, Tail...> {
    typedef tup<Tail...> composited;

protected:
    composited m_tail;
    Head m_head;

public:
    tup() {}
    tup(Head v, Tail... vtail) : m_tail(vtail...), m_head(v) {}

    Head head() { return m_head; }
    composited& tail() { return m_tail; } //&ref: can change val
};


void test1() {
    tup<int, float, string> it1(12, 1.2, "hello");
    cout << sizeof(it1) << endl;
    cout << it1.head() << endl;
    cout << it1.tail().head() << endl;
    cout << it1.tail().tail().head() << endl;
}

void test2() {
    tup<string, complex<int>, bitset<16>, double> it2("Ace", complex<int>(3, 8),
                                                      bitset<16>(234), 3.4);
    cout << sizeof(it2) << endl;
    cout << it2.head() << endl;
    cout << it2.tail().head() << endl;
    cout << it2.tail().tail().head() << endl;
    cout << it2.tail().tail().tail().head() << endl;
    it2.tail().tail().tail() = *(new tup<double>(1.22));
    cout << it2.tail().tail().tail().head() << endl;
}

/*
48
12
1.2
hello
---------------
56
Ace
(3,8)
0000000011101010
3.4
*/
int main(int argc, char const* argv[]) {
    test1();
    cout << "---------------" << endl;
    test2();
    return 0;
}