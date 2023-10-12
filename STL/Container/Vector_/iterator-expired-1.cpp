#include <vector>
#include <format>
#include <iostream>
using namespace std;

vector<int> arr{1, 2, 3};
auto IFS = string(20, '=');
auto it1 = arr.begin();
auto it2 = arr.begin() + 1;


void get_info() {
    cout << format("size={}, capacity={}\n", arr.size(), arr.capacity());
    if (*it1 != 1 or *it2 != 2) {
        cout << "iterator expired\n";
    }
    cout << "now arr is: ";
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << format("\niter1={}, iter2={}\n", *it1, *it2);
}

void t1() {
    get_info();
    cout << format("{} after operating {}\n", IFS, IFS);
    // 只要涉及了内存的重新分配, 一定会导致迭代器失效,
    // expired:
    // arr.resize(5);
    // arr.reserve(5);
    arr.push_back(4);
    // arr.insert(arr.end(), 12);
    // arr.insert(arr.begin(), 12);
    // arr.erase(arr.begin());

    // non-expired:
    // arr.erase(arr.end()); // gcc 未做边界检查, 所以导致删除了最后一个元素
    // arr.erase(arr.end() - 1);

    // vector<int> v{4, 5, 6};
    // arr.swap(v);
    get_info();
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
