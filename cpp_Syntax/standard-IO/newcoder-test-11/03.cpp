#include <cstdio>

using namespace std;

int main(void) {
    int a, b;
    while (~scanf("%d %d", &a, &b)) {
        if (!a || !b) break;
        printf("%d\n", a + b);
    }
    return 0;
}
