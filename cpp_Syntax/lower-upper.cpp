#include <iostream>

using namespace std;
int main(int argc, char const *argv[]) {
    auto tolower = [](char c) {
        return islower(c) ? c : static_cast<char>(c | 0x20);
    };
    auto toupper = [](char c) {
        return isupper(c) ? c : static_cast<char>(c & ~0x20);
    };
    cout << toupper('c') << endl;
    cout << tolower('C') << endl;
    return 0;
}