#include <stdio.h>
#include <stdlib.h>
#include <sys/_select.h>
#include <sys/_types/_fd_def.h>
#include <sys/_types/_timeval.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>

const int BUF_SIZE = 30;

int main(int argc, char *argv[]) {
    fd_set reads, temps;
    int res, str_len;
    char buf[BUF_SIZE];
    struct timeval timeout;
    FD_ZERO(&reads);
    // watch stdin change
    FD_SET(0, &reads); // 0 is std in

    // can not set here, otherwise select will override the params
    /* timeout.tv_sec=5; */
    /* timeout.tv_usec=5000; */

    while (1) {
        // remember init value
        //  otherwise select() will change `reads`
        temps = reads;
        // every call select(), timeval will be initialized
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        res = select(1, &temps, 0, 0, &timeout);

        if (res == -1) {
            puts("select() error");
            break;
        } else if (res == 0)
            puts("timeout..");
        else {
            // is stdin:
            if (FD_ISSET(0, &temps)) {
                str_len = read(0, buf, BUF_SIZE);
                buf[str_len] = 0;
                printf("msg :%s \n", buf);
            }
        }
    }
    return 0;
}
