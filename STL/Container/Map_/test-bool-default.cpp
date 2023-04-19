#include <map>
#include <iostream>
using namespace std;
ostream &operator<<(ostream &os, const map<string, bool> &mp) {
    os << "{";
    for (auto &p : mp) {
        os << "<" << p.first << ": " << p.second << ">";
        os << ", ";
    }
    os << "}" << endl;
    return os;
}
int main(int argc, char const *argv[]) {
    map<string, bool> mhash{};
    cout << mhash["a"] << endl;
    if (mhash["a"] != false) mhash["a"] = true;
    cout << mhash << endl;
    return 0;
}
