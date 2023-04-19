#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    cout << sizeof(vector<string>) << endl; // 24, 3ptrs
    return 0;
}