#include <iostream>
#include <string>

using namespace std;

string toLowerCase(string str) {
    string new_str(str);
    for (size_t i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            new_str[i] = (char)((int)str[i] | 0x20); // equals to +32(if upper)
        }
    }
    return new_str;
}

string toUpperCase(string str) {
    string new_str(str);
    for (size_t i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            new_str[i] = (char)((int)str[i] & ~0x20); // equals to -32(if lower)
        }
    }
    return new_str;
}

int main(int argc, char const *argv[]) {
    string ss = "Here";
    cout << ss << endl;
    cout << toLowerCase(ss) << endl;
    cout << toUpperCase(ss) << endl;
    return 0;
}
