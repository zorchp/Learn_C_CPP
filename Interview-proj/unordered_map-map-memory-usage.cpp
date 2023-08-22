#include <bits/stdc++.h>
using namespace std;

void t1() {
    unordered_map<int, int> ump;
    map<int, int> mp;
    for (int i{}; i < 1'0000; ++i) {
        // mp.insert(pair{i, i});
        ump.insert(pair{i, i});
        assert(ump.load_factor() <= 1);
    }
    cout << ump.load_factor() << endl;
    cout << ump.max_load_factor() << endl;
    cout << ump.bucket_count() << endl;     // 12853
    cout << ump.max_bucket_count() << endl; // 768614336404564650

    int size{};
    map<int, int> st;
    for (int i{}; i < ump.bucket_count(); ++i) {
        // size += ump.bucket_size(i);
        auto tmp = ump.bucket_size(i);
        if (tmp > 0) {
            ++st[tmp];
        }
        // cout << ump.bucket_size(i) << endl;
    }

    for (auto [k, v] : st) {
        cout << k << ": " << v << endl;
    }

    // clang++
    //  cout << sizeof(mp) << endl;  // 24
    //  cout << sizeof(ump) << endl; // 40
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
