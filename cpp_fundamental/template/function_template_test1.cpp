#include <iostream>
using namespace std;

class stone {
public:
    stone() {}
    stone(int w, int h, int we) : m_w(w), m_h(h), m_we(we) {}
    bool operator<(const stone& rhs) const { return m_we < rhs.m_we; }
    int get_we() const { return m_we; }

private:
    int m_w, m_h, m_we;
};

template <class T>
inline const T& min1(const T& a, const T& b) {
    return b < a ? b : a;
}

void test1() {
    stone r1(2, 1, 3), r2(3, 2, 39), r3;
    r3 = min1(r1, r2);
    // r3 = min1<stone>(r1, r2);
    cout << r1.get_we() << endl;
    cout << r2.get_we() << endl;
    cout << r3.get_we() << endl;
}

int main(int argc, char const* argv[]) {
    test1();

    return 0;
}
