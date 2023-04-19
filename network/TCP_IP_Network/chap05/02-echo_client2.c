#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_endian.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *msg);

const int BUF_SIZE = 1024;

int main(int argc, char *argv[]) {
    int sock;

    struct sockaddr_in serv_addr;
    char msg[30];
    int str_len;
    /* int idx = 0, read_len = 0; */

    if (argc != 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error");
    else
        puts("connected ...........");

    // receive len and count
    int recv_len, recv_cnt;

    /* char *fs = " [from server]"; */
    while (1) {
        fputs("Input msg(q to quit)", stdout);
        fgets(msg, BUF_SIZE, stdin);
        if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n")) break;
        // 写入客户端套接字, 然后重新从服务器端发来的msg中读取
        if ((str_len = write(sock, msg, strlen(msg))) == -1)
            error_handling("write to sock error\n");
        recv_len = 0;
        str_len += 14;
        while (recv_len < str_len) {
            recv_cnt = read(sock, &msg[recv_len], BUF_SIZE - 1);
            /* printf("msg=%s\n", msg); */
            /* printf("recv_cnt=%d\n", recv_cnt); */
            if (recv_cnt == -1) {
                error_handling("read() error");
            }
            recv_len += recv_cnt;
        }

        /* str_len = read(sock, msg, BUF_SIZE - 1); */
        /* printf("recv_len=%d\n", recv_len); */
        msg[recv_len] = '\0';
        printf("Msg from server: %s\n", msg);
    }
    close(sock);

    return 0;
}

void error_handling(char *msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
