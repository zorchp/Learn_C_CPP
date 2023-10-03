#include <iostream>

using namespace std;


template <int IDX, int MAX, typename... Args>
struct PRINT_TUPLE {
    static void print(ostream& os, const tuple<Args...>& t) {
        os << get<IDX>(t) << (IDX + 1 == MAX ? "" : ", ");
        // 递增索引
        PRINT_TUPLE<IDX + 1, MAX, Args...>::print(os, t);
    }
};


template <typename... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    os << "[";
    // sizeof...(Args)获得元素个数
    PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os, t);
    return os << "]";
}

// recur terminate
template <int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...> {
    static void print(ostream& os, const tuple<Args...>& t) {}
};


int main(int argc, char const* argv[]) {
    cout << make_tuple(7.5, string("hello"), bitset<12>(210)) << endl;
    return 0;
}