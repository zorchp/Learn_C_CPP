#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char const *argv[]) {
    int ia[6] = {2, 4, 6, 94, 338};
    vector<int, allocator<int> > vi(ia, ia + 6);
    // std::function<bool(int)> lmbd = [] (int a) {return a<40;};
    // cout<<count_if(vi.begin(), vi.end(), not1(lmbd));
    cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40)));

    return 0;
}
