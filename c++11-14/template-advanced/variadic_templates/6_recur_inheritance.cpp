#include <iostream>
#include <string>
#include <tuple>


using namespace std;


/*
递归继承
*/

// template<typename... Values> class tuple;
// template<> class tuple<> {};


template <typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...> {
    typedef tuple<Tail...> inherited; // 并不是类的重命名,代表递归继承父类

    // (!)
    // protected:
    //   Head m_head;
public:
    tuple() {}
    tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) {}

    // typename Head::type head() {return m_head;}//error
    // auto head()->decltype(m_head) {return m_head;}// √,need first declare(!)
    // m_head
    Head head() { return m_head; }      //√
    inherited& tail() { return *this; } // 返回自身
protected:
    Head m_head;
};

/*
32
41
4.3
nice
0x16d8bf460
*/

int main(int argc, char const* argv[]) {
    tuple<int, float, string> t(41, 4.3, "nice");
    cout << sizeof(t) << endl;
    cout << t.head() << endl;
    // cout<<t.tail();
    cout << t.tail().head() << endl;
    cout << t.tail().tail().head() << endl;
    cout << &(t.tail()) << endl;
    return 0;
}