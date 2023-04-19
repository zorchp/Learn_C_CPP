#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

namespace jj30 {
void test_all_components() {
    cout << "\ntest_all_components().......... \n";

    int ia[7] = {27, 210, 12, 47, 109, 83, 40};
    vector<int, allocator<int>> vi(ia, ia + 7);

    cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40))); // 5
    cout << endl;
    /*clang:
    func_adapter_bind2nd.cpp:15:27: error: use of undeclared identifier
    'bind2nd' not1(bind2nd(less<int>(), 40)));   //5
                          ^
    1 error generated.
    */
}
} // namespace jj30

int main(int argc, char const *argv[]) {
    jj30::test_all_components();
    return 0;
}