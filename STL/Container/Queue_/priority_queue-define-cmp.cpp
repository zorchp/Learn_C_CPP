#include <queue>
#include <vector>
#include <iostream>
using namespace std;
struct cmp {
    using pii = pair<int, int>;
    bool operator()(const pii &lhs, const pii &rhs) const {
        return lhs.first < rhs.first;
    }
};

void t1() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.emplace(1, 3);
    pq.emplace(4, 2);
    pq.emplace(6, 2);
    for (; !pq.empty(); pq.pop()) {
        auto [k, v] = pq.top();
        cout << k << " : " << v << endl;
    }
    // 6 : 2
    // 4 : 2
    // 1 : 3
}


void t2() {
    auto cmp = [](const auto &lhs, const auto &rhs) {
        return lhs.first < rhs.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);
    pq.emplace(1, 3);
    pq.emplace(4, 2);
    pq.emplace(6, 2);
    for (; !pq.empty(); pq.pop()) {
        auto [k, v] = pq.top();
        cout << k << " : " << v << endl;
    }
    // 6 : 2
    // 4 : 2
    // 1 : 3
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
