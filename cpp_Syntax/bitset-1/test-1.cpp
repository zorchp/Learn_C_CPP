#include <bitset>
#include <iostream>
using namespace std;
void t1() {
    bitset<32> a(12);
    int N = a.size();
    int c = a.count();
    for (int i{}; i < N; ++i) cout << a[i] << " ";
    cout << endl;
    cout << c << endl; // 2
    cout << a.flip() << endl;
}

bool queryString(string s, int n) {
    for (int i{1}; i <= n; ++i) {
        string sub{};
        int k{i};
        while (k) {
            sub.push_back(char(k % 2 + '0'));
            k /= 2;
        }
        reverse(sub.begin(), sub.end());
        // cout<<sub;
        if (s.find(sub) == string::npos) return false;
    }
    return true;
}
void t2() {
    cout << queryString("0110", 3); //
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}
