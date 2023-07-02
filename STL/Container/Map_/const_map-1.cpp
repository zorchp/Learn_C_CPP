#include <map>
#include <iostream>
using namespace std;

using mii = std::map<int, int>;

void t1() {
    mii st;
    st[0] = 1;
    st.at(0) = 1;
    st.insert(mii::value_type(1, 2));
    for (auto [k, v] : st)
        cout << k << " : " << v << endl;
    // 0 : 1
    // 1 : 2
}

void t2() {
    const mii st;
    // st[0] = 1; // error
    // st.insert_or_assign(1, 1);
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
