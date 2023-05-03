#include <iostream>

using namespace std;

void exchange(int &a, int &b) {
    int temp = a;
    a        = b;
    b        = temp;
}

int main() {
    int arr[] = {1, 2, 4, 5, 3, 6};

    for (int i = 0; i < 6; ++i) { cout << arr[i] << " "; }
    cout << endl;
    int start = 0;
    int end   = sizeof(arr) / sizeof(arr[0]) - 1;
    for (; start < end; start++, end--) {
        // int t=arr[start];
        // arr[start] = arr[end];
        // arr[end]=t;
        exchange(arr[start], arr[end]);
    }
    for (int i = 0; i < 6; ++i) { cout << arr[i] << " "; }
    cout << endl;
    return 0;
}