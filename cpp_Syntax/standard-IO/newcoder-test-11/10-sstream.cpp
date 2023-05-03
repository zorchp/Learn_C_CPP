#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        vector<string> ves;
        string item;
        stringstream ss(s);
        while (getline(ss, item, ',')) ves.push_back(item);
        sort(ves.begin(), ves.end());
        for (int i = 0; i < ves.size(); i++) {
            cout << ves[i];
            if (i != ves.size() - 1) cout << ',';
        }
        cout << endl;
    }
}