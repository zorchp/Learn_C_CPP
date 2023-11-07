#include <bits/stdc++.h>
using namespace std;

const string vowel = "aeiuo";
const unordered_set<char> st(vowel.begin(), vowel.end());
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        return count_if(
            words.begin() + left, words.begin() + right + 1,
            [](auto w) { return st.count(w.front()) and st.count(w.back()); });
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<string> v = {"aa", "are", "v", "w"};
    cout << s.vowelStrings(v, 1, 3) << endl;
    return 0;
}
