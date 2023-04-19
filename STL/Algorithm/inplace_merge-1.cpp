#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    int iarray[] = {
        1, 3, 5, 2, 4, 6,
    };
    vector<int> ivector(iarray, iarray + sizeof(iarray) / sizeof(int));
    inplace_merge(ivector.begin(), ivector.begin() + 3, ivector.end());
    copy(ivector.begin(), ivector.end(), ostream_iterator<int>(cout, " "));
    cout << endl; // 1 2 3 4 5 6
    return 0;
}