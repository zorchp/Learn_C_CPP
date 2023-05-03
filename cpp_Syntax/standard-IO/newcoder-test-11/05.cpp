#include <cstdio>

using namespace std;

int main(void) {
    int a, m, n, sum;
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &n);
        sum = 0;
        while (n--) scanf("%d", &a), sum += a;
        printf("%d\n", sum);
    }
    return 0;
}
