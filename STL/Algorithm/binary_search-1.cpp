#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define SIZE(x) ((sizeof(x)) / (sizeof(x[0])))

int arr[]{1, 2, 3, 4, 4, 4, 5, 6, 9};
vector v{1, 2, 3, 4, 4, 4, 5, 6, 9};

void t1() {
    auto i = binary_search(v.begin(), v.end(), 4);
    auto j = binary_search(v.begin(), v.end(), 40);

    cout << i << endl; // 1, true
    cout << j << endl; // 0, false
}

// just like [begin, end)
void t2() {
    auto it = lower_bound(v.begin(), v.end(), 4);
    cout << *it << endl;                     // 4
    cout << distance(v.begin(), it) << endl; // 3, index of the first item
}

void t3() {
    auto it = upper_bound(v.begin(), v.end(), 4);
    cout << *it << endl; // 5
    cout << distance(v.begin(), it)
         << endl; // 6, index of next of the last item
}

void t4() {
    auto idx = lower_bound(arr, arr + SIZE(arr), 4);
    cout << idx << endl;       // addr of found element
    cout << *idx << endl;      // 4
    cout << idx - arr << endl; // 3
    idx = upper_bound(arr, arr + SIZE(arr), 4);
    cout << idx << endl;       // addr of found element
    cout << *idx << endl;      // 5
    cout << idx - arr << endl; // 6
}

void t5() {
    // user definition compare rule
    using MapType = pair<int, string>;
    MapType marr[]{
        {1, "one"}, {2, "two1"}, {2, "two2"}, {2, "two3"}, {3, "three"} //
    };
    int value_to_found = 2;
    auto it = lower_bound(marr, marr + SIZE(marr), value_to_found,
                          [&](const auto &lhs, const auto &) {
                              return lhs.first < value_to_found;
                          });
    cout << it << endl;
    cout << it->second << endl;         // two1
    cout << it - marr << endl;          // 1
    cout << distance(marr, it) << endl; // 1
}

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    // t3();
    // t4();
    t5();
    return 0;
}