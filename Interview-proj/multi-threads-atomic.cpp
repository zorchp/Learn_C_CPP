#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

const int SIZE = 10;

void printArray(int arr[]) {
    for (int i = 0; i < SIZE; i++) { cout << arr[i] << " "; }
    cout << endl;
}

int main() {
    int arr1[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int arr2[SIZE] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    atomic<bool> turn(false);

    thread t1([&]() {
        for (int i = 0; i < SIZE; i++) {
            while (turn) {}
            printArray(arr1);
            turn = true;
        }
    });

    thread t2([&]() {
        for (int i = 0; i < SIZE; i++) {
            while (!turn) {}
            printArray(arr2);
            turn = false;
        }
    });

    t1.join();
    t2.join();

    return 0;
}
