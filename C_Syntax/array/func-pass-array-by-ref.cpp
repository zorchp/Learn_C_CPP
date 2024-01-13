#include <iostream>

void f(int* arr) { arr[1] = 19; }

void g(int (&arr)[5]) { arr[1] = 19; }

void t1() {
    int arr[] = {1, 2, 3, 4, 5};
    // f(arr);
    g(arr);
    std::cout << arr[1] << std::endl;
}

int main(int argc, char* argv[]) {
    t1();
    return 0;
}
