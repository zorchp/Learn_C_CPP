#include <chrono>
#include <iostream>
#include <set>
using namespace std;
void t1() {
    std::set<int> st;
    for (int i{}; i < 1000000; ++i) {
        // for POD type
        st.insert(i % 3);  // Time spent: 0.082356s
        st.emplace(i % 3); // Time spent: 0.202839s
    }
}

class P {
    [[maybe_unused]] int x;

public:
    P() { cout << __PRETTY_FUNCTION__ << endl; }
    P(int) { cout << __PRETTY_FUNCTION__ << endl; }
    // must defined this rule for associated container
    bool operator<(const auto& rhs) const { return x < rhs.x; }

    ~P() { cout << __PRETTY_FUNCTION__ << endl; }
    P(const P&) { cout << __PRETTY_FUNCTION__ << endl; }
    P& operator=(const P&) {
        cout << __PRETTY_FUNCTION__ << endl;
        return *this;
    }
    P(P&&) { cout << __PRETTY_FUNCTION__ << endl; }
    P& operator=(P&&) {
        cout << __PRETTY_FUNCTION__ << endl;
        return *this;
    }
};

class Q {
    int x;

public:
    Q(int) {}
    bool operator<(const auto& rhs) const { return x < rhs.x; }
};

void t2() {
    // set<P> st;
    set<Q> st;
    constexpr int test_num = 10000000;
    for (int i{}; i < test_num; ++i) {
        // for user-defined type
        st.insert(i % 3); // Time spent: 0.404755s
        // st.emplace(i % 3); // Time spent: 0.980151s
    }
}

int main(int argc, char* argv[]) {
    auto start = std::chrono::system_clock::now();

    // t1();
    t2();

    auto end = std::chrono::system_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time spent: "
              << double(duration.count()) *
                     std::chrono::microseconds::period::num /
                     std::chrono::microseconds::period::den
              << "s" << std::endl;
    return 0;
}
