#include <bits/stdc++.h>

using namespace std;

stack<int> st1;
stack<int, list<int>> st2;
stack<int, forward_list<int>> st3;
void t1() {
    cout << typeid(st1).name() << endl;
    cout << typeid(st2).name() << endl;
    cout << typeid(st3).name() << endl;
    // NSt3__15stackIiNS_5dequeIiNS_9allocatorIiEEEEEE
    // NSt3__15stackIiNS_4listIiNS_9allocatorIiEEEEEE
    // NSt3__15stackIiNS_12forward_listIiNS_9allocatorIiEEEEEE
}

constexpr int N = 10000000;

// just for g++
template <template <typename> class C>
void test(stack<int, C<int>> &st) {
    for (int i{}; i < N; ++i) {
        st.push(i);
    }
    // for (int i{}; i < N; ++i) {
    //     st.pop();
    // }
}

void t2() {
    auto start = std::chrono::system_clock::now();

    test(st2);

    auto end = std::chrono::system_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time spent: "
              << double(duration.count()) *
                     std::chrono::microseconds::period::num /
                     std::chrono::microseconds::period::den
              << "s" << std::endl;
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
