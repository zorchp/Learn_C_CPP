#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_select.h>
#include <sys/_types/_fd_def.h>
#include <sys/_types/_socklen_t.h>
#include <sys/_types/_timeval.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>

const int BUF_SIZE = 30;
void error_handling(char *msg);

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    fd_set reads, cpy_reads;
    socklen_t addr_size;

    int fd_max, str_len, fd_num, i;

    char buf[BUF_SIZE];
    struct timeval timeout;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1) error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");

    if (listen(serv_sock, 5) == -1) error_handling("listen() error");

    FD_ZERO(&reads);
    // watch stdin change
    FD_SET(serv_sock, &reads); // 0 is std in
    fd_max = serv_sock;

    while (1) {
        // remember init value
        //  otherwise select() will change `reads`
        cpy_reads = reads;
        // every call select(), timeval will be initialized
        timeout.tv_sec = 5;
        timeout.tv_usec = 5000;
        // the 3rd,4th param:0, trivial
        // only pay attention to `read`
        fd_num = select(fd_max + 1, &cpy_reads, 0, 0, &timeout);
        /* printf("fd_num:%d \n", fd_num); */
        if (fd_num == -1) break;

        if (fd_num == 0) continue;
        for (i = 0; i < fd_max + 1; i++) {
            // find which fd is changed
            if (FD_ISSET(i, &cpy_reads)) {
                if (i == serv_sock) { // connection request!
                    addr_size = sizeof(clnt_addr);
                    clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr,
                                       &addr_size);
                    // login reads info
                    FD_SET(clnt_sock, &reads);
                    if (fd_max < clnt_sock) fd_max = clnt_sock;
                    printf("connected client :%d \n", clnt_sock);
                } else {
                    str_len = read(i, buf, BUF_SIZE);
                    if (str_len == 0) {
                        FD_CLR(i, &reads);
                        close(i);
                        printf("close client :%d \n", i);
                    } else
                        write(i, buf, str_len); // echo
                }
            }
        }
    }
    printf("close server...");
    close(serv_sock);
    return 0;
}

void error_handling(char *msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
