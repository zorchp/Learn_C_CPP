#include <iostream>
using namespace std;

int main() {
    constexpr int num = 1 + 2 + 3;
    int url[num] = {1, 2, 3, 4, 5, 6};
    for (auto &i : {0, 1, 2, 3, 4, 5}) { cout << url[i] << endl; }
    return 0;
}