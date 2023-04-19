#include <iostream>
#include <vector>
using namespace std;


void t1() {
    vector<int> v1{1, 2, 3, 4, 5};
    for (int i{1}; i <= 5; ++i)
        cout << v1.begin()[i - 1] << " " << v1.end().operator[](-i) << endl;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}
