#include <cstdio>
#include <cstdlib>
#include <cstring>


int main(int argc, char *argv[]) {
    int arr[2][3]{};
    arr[0][1] = 1, arr[0][2] = 12;
    for (int i{}; i < 3; ++i) printf("%d\t", arr[0][i]);
    std::putchar('\n');
    memcpy(arr + 1, arr, sizeof(arr[0]));
    for (int i{}; i < 3; ++i) printf("%d\t", arr[1][i]);
    std::putchar('\n');
    return 0;
    // 0       1       12
    // 0       1       12
}
