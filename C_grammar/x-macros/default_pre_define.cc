#include <iostream>
using namespace std;

#define LOG(x)                                                                 \
    (cout << __FILE__ << " " << __LINE__ << ": " << __PRETTY_FUNCTION__ << (x) \
          << endl)


void t1() { LOG("hello"); }

template <typename T>
void t2(T s) {
    LOG(s);
    cout << __TIME__ << endl;
    cout << __DATE__ << endl;
    cout << __func__ << endl;
    /*
    gcc_pre_define.cc 13: void t2(T) [with T = char]1
    00:17:03
    Aug 24 2022
    t2
    */
}

int main(int argc, char const *argv[]) {
    // t1();
    t2('1');
    return 0;
}