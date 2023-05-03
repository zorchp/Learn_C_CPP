#include <cstdio>

using namespace std;

int main(void) {
    int a, sum{};
    while (~scanf("%d", &a)) {
        sum += a;
        if (getchar() == '\n') {
            printf("%d\n", sum);
            sum = 0;
        }
    }
    return 0;
}
