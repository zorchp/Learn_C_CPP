#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

void t1() {
    std::vector<int> v1{1, 2, 3}, v2{1, 2, 7};
    int i{};
    while (v1 != v2) {
        v2[2] -= 1;
        v2 = v1;
        i++;
    }
    cout << i << endl;
}


int main(int argc, char const *argv[]) {
    t1();
    return 0;
}