#include <stdio.h>
int s = 0;
int a[1005] = {0};
void QSort(int a[], int m, int n) {
    if (m < n) {
        int i = m;
        int j = n + 1;
        int c = a[m];
        while (i < j) {
            i++;
            while (a[i] <= c && i < n) { i++; }
            j--;
            while (a[j] > c && j >= 0) { j--; }
            if (i < j) {
                int d = a[i];
                a[i] = a[j];
                a[j] = d;
            }
        }
        int d = a[j];
        a[j] = a[m];
        a[m] = d;
        for (int i = 0; i < s; i++) { printf("%d ", a[i]); }
        printf("\n");
        QSort(a, m, j - 1);
        QSort(a, j + 1, n);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    s = n;
    for (int i = 0; i < n; i++) { scanf("%d", &a[i]); }
    QSort(a, 0, n - 1);
    for (int i = 0; i < s; i++) { printf("%d ", a[i]); }
    printf("\n");
}
