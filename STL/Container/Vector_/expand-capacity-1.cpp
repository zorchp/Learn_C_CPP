#include <iostream>

using namespace std;

void t1() {
    vector<int> v;
    cout << v.size() << " : " << v.capacity() << endl;
    v.reserve(7); // 扩容机制由 capacity 决定, capacity 的二倍
    for (int i{}; i < 100; ++i) {
        v.emplace_back(i);
        cout << v.size() << " : " << v.capacity() << endl;
    }
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
