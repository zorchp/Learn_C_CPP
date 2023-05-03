#include <vector>
#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {
    vector<int> a{1, 2, 3, 4, 5};
    cout << *a.end() << endl;    // 0
    cout << a.end()[-1] << endl; // 5
    cout << a.end()[-2] << endl; // 4
    return 0;
}