#include <iostream>
using namespace std;

namespace blip {
int i = 16, j = 15, k = 23;
} // namespace blip

int j = 0;
void manip() {
    using namespace blip;
    ++i;
    cout << "i=" << i << endl;             // 17
    cout << "blip::i=" << blip::i << endl; // 17
    // ++j;//error: reference to 'j' is ambiguous
    ++::j;
    ++blip::j;
    cout << "::j=" << ::j << endl;         // 1
    cout << "blip::j=" << blip::j << endl; // 16
    int k = 97;
    ++k;                                   // local k, not blip::k
    cout << "k=" << k << endl;             // 98
    cout << "blip::k=" << blip::k << endl; // 23
}


int main(int argc, char const *argv[]) {
    manip();
    return 0;
}