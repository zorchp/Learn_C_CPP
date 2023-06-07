#include <sys/filio.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int kbhit() {
    int i;
    ioctl(0, FIONREAD, &i);
    return i;
}
int main() {
    int i = 0;
    int c = ' ';
    /* 返回可以读取􏰒字符􏰒计数􏱕 */

    system("stty raw –echo");
    printf("enter ’q’ to quit \n");
    for (; c != 'q'; i++) {
        sleep(1);
        if (kbhit()) {
            c = getchar();
            printf("\n got %c, on iteration %d", c, i);
        }
    }
    system("stty cooked echo");
}
