#include <cstddef>
#include <functional> // std::minus
#include <iostream>   // std::cout
#include <numeric>    // std::accumulate
using namespace std;

namespace jj34 {
int myfunc(int x, int y) {
    return x + 2 * y;
}

struct myclass {
    int operator()(int x, int y) {
        return x + 3 * y;
    }
} myobj;

void test_accumulate() {
    cout << "\ntest_accumulate().......... \n";
    int init = 100;
    int nums[] = {10, 20, 30};

    cout << "using default accumulate: ";
    cout << accumulate(nums, nums + 3, init); // 160
    cout << '\n';

    cout << "using functional's minus: ";
    cout << accumulate(nums, nums + 3, init, minus<int>()); // 40
    cout << '\n';

    cout << "using custom function: ";
    cout << accumulate(nums, nums + 3, init, myfunc); // 220
    cout << '\n';

    cout << "using custom object: ";
    cout << accumulate(nums, nums + 3, init, myobj); // 280
    cout << '\n';
}
} // namespace jj34
/*
test_accumulate()..........
using default accumulate: 160
using functional's minus: 40
using custom function: 220
using custom object: 280
Press ENTER to exit!
*/

void t2() {
    vector v{1, 3, 5, 7, 9};
    cout << accumulate(v.begin(), v.end(), 0LL,
                       [](int acc, int num) { return acc += num + 1; });
    // 30=25+5
}

int main(int argc, char const *argv[]) {
    // jj34::test_accumulate();
    t2();
    return 0;
}
