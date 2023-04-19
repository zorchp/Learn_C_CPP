#include <iostream>
#include <string>

using namespace std;

string toLowerCase(string str) {
    string new_str(str);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            new_str[i] = (char)((int)str[i] + 32);
        } else {
            new_str[i] = str[i];
        }
    }
    return new_str;
}

int main(int argc, char const *argv[]) {
    string ss = "Here";
    cout << ss << endl;
    cout << toLowerCase(ss) << endl;
    return 0;
}
