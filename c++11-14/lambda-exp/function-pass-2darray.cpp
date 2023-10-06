#include <iostream>
#include <functional>

void printArray(int (*arr)[3],
                int size) { // declare a function that takes a 2D array
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}}; // define a 2D array
    std::function<void(int(*)[3], int)> func =
        printArray; // create a function object
    func(arr, 2);   // call the function object
    return 0;
}
