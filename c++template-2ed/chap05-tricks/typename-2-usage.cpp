#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printcoll(T const &coll) {
    typename T::const_iterator pos;
    typename T::const_iterator end(coll.end());

    for (pos = coll.begin(); pos != end; ++pos) {
        cout << *pos << endl;
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    vector<int> v{1, 2, 3};
    printcoll(v);
    return 0;
}
