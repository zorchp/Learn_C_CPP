#include <cstdio>
#include <climits>

int main(int argc, char const *argv[]) {
    int m = 10;
    int n = 20;
    int a[m][n] = {INT_MIN}; // just for G++
    for (int i{}; i < m; ++i) {
        for (int j{}; j < n; ++j) {
            printf("%d\t", a[i][j]);
        }
        putchar('\n');
    }
    return 0;
}