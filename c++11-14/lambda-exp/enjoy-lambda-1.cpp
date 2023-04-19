#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 5;

int main(int argc, char const *argv[]) {
    int arr[SIZE] = {1, 2, 3};
    // vector<int> arr{1, 2, 3}; // error
    for (int i = 0; i < SIZE; ++i) cout << i[arr] << " " << arr[i] << endl;
    cout <<
        [arr]() {
            0;
            return 0;
        }()[arr]
         << endl;
    return 0;
}
