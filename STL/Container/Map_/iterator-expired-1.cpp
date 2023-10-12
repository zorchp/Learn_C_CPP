#include <map>
#include <format>
#include <iostream>
using namespace std;

map<int, int> mp{{1, 1}, {2, 2}, {3, 3}};
auto IFS = string(20, '=');
auto it1 = mp.begin();
auto it2 = mp.rbegin(); // tail data node


void get_info() {
    cout << format("size={}, max_size={}\n", mp.size(), mp.max_size());
    cout << format("iter1={}:{}, iter2={}:{}\n", it1->first, it1->second,
                   it2->first, it2->second);
}

void t1() {
    get_info();
    cout << format("{} after operating {}\n", IFS, IFS);
    // expired:
    // mp.insert({4, 4});

    // non-expired:
    // mp.erase(2);
    [[maybe_unused]] map<int, int> tmp{{5, 5}, {6, 6}};
    // mp.swap(tmp);
    get_info();
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
