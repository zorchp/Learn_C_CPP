#include <cassert>
#include <iostream>
#include <new>
using namespace std;

namespace jj13 {
void noMoreMemory() {
    cerr << "out of memory\n";
    abort();
}

void test_set_new_handler() {
    cout << "\n\n\ntest_set_new_handler().......... \n";

    set_new_handler(noMoreMemory);


    int* p = new int[100000000000000]; // well, so BIG!
    assert(p);

    // p = new int[100000000000000000000L];  //[Warning] integer constant is too
    // large for its type assert(p);
    /*
    test_set_new_handler()..........
    out of memory[1]    16835 abort
    */

    // if not set_new_handler:
    /*
    test_set_new_handler()..........
    terminate called after throwing an instance of 'std::bad_alloc'
    what():  std::bad_alloc
    [1]    17936 abort

    */
}
} // namespace jj13

int main(int argc, char const* argv[]) {
    jj13::test_set_new_handler();
    return 0;
}