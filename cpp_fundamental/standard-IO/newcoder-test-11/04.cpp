#include <cstdio>

using namespace std;

int main(void) {
    int a, n, sum;
    while (~scanf("%d", &n)) {
        if (!n) break;
        sum = 0;
        while (n--) scanf("%d", &a), sum += a;
        printf("%d\n", sum);
    }
    return 0;
}
