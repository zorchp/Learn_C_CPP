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
    int serv_sock;
    int clnt_sock;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    /* char msg[] = "hello network!"; */
    char msg[BUF_SIZE];
    int str_len, i;

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

    // 处理3个客户端连接, 调用3次accept, **依次**向3个客户端提供服务.
    if (listen(serv_sock, 3) == -1) error_handling("listen() error");
    clnt_addr_size = sizeof(clnt_addr);
    for (i = 0; i < 3; ++i) {
        clnt_sock =
            accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
        if (clnt_sock == -1)
            error_handling("accept() error");
        else
            printf("Connected client %d \n", i + 1);

        /* char *fs = " [from server]\n"; */
        char add[30];
        char *tmp = " *from_server* ";
        strcpy(add, tmp);
        // 读取客户端套接字msg, 并写入客户端套接字
        while ((str_len = read(clnt_sock, msg, BUF_SIZE)) != 0) {
            printf("msg from client: %s", msg);
            /* str_len += strlen(fs) - 1; */
            printf("str_len=%d\n", str_len);
            /* if (msg[str_len] == '\0') strcat(msg, fs); */
            /* msg[0] += 1; // ok */
            /* strcat(add, msg); */
            msg[str_len - 1] = 0;
            strcat(msg, tmp);
            write(clnt_sock, msg, str_len + 15);
            // reset msg
            memset(msg, 0, sizeof(msg));
        }
        printf("Disconnected client %d \n", i + 1);
        close(clnt_sock);
    }
    printf("Close server\n");
    close(serv_sock);

    return 0;
}

void error_handling(char *msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
