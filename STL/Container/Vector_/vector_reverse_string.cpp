#include <iostream>
#include <vector>

using namespace std;

void reverseVec(vector<char> &s) {
    for (int i = 0; i < s.size() / 2; i++) {
        char t = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = s[i];
        s[i] = t;
    }
}

void printStr(vector<char> &s) {
    for (int i = 0; i < s.size(); i++) { cout << s[i]; }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    vector<char> s;
    // s.assign(5, 's');
    s.push_back('h');
    s.push_back('e');
    s.push_back('l');
    s.push_back('l');
    s.push_back('o');
    printStr(s);
    // cout<<s[1]<<endl;
    // reverseVec(s);
    reverse(s.begin(), s.end());
    printStr(s);
    return 0;
}
