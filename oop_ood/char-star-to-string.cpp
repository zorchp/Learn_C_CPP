#include <iostream>
#include <string>
using namespace std;
class S {
    string m_s;

public:
    S(const char* s) : m_s(s) {
        if (m_s.size() > 3) cout << "aa\n";
    }
};

void t1() {
    //
    S s1("abc");
}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}