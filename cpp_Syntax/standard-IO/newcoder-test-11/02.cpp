#include <cstdio>

using namespace std;

int main(void) {
    int a, b, n;
    scanf("%d", &n);
    while (n--) scanf("%d %d", &a, &b), printf("%d\n", a + b);
    return 0;
}
