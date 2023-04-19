#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/socket.h>
#include <fcntl.h>

void error_handling(char *msg);
void urg_handler(int signo);
const int BUF_SIZE = 30;

int acpt_sock;
int recv_sock;

int main(int argc, char *argv[]) {

    struct sockaddr_in serv_addr, recv_addr;
    socklen_t serv_addr_size;

    struct sigaction act;
    char buf[BUF_SIZE];
    int str_len, state;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    act.sa_handler = urg_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    acpt_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (acpt_sock == -1) error_handling("socket() error");

    memset(&recv_addr, 0, sizeof(recv_addr));
    recv_addr.sin_family = AF_INET;
    recv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    recv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(acpt_sock, (struct sockaddr *)&recv_addr, sizeof(recv_addr)) == -1)
        error_handling("bind() error");

    if (listen(acpt_sock, 5) == -1) error_handling("listen() error");

    serv_addr_size = sizeof(serv_addr);
    recv_sock =
        accept(acpt_sock, (struct sockaddr *)&serv_addr, &serv_addr_size);
    if (recv_sock == -1) error_handling("accept() error");

    fcntl(recv_sock, F_SETOWN, getpid());
    state = sigaction(SIGURG, &act, 0);
    printf("state=%d\n", state);

    // 读取客户端套接字buf, 并写入客户端套接字
    while ((str_len = recv(recv_sock, buf, sizeof(buf), 0)) != 0) {
        if (str_len == -1) continue;
        buf[str_len] = 0;
        puts(buf);
        /* printf("%s \n", buf); */
    }

    close(recv_sock);
    close(acpt_sock);

    return 0;
}

void urg_handler(int signo) {
    int str_len;
    char buf[BUF_SIZE];
    str_len = recv(recv_sock, buf, sizeof(buf) - 1, MSG_OOB);
    buf[str_len] = 0;
    printf("Urgent msg: %s \n", buf);
}

void error_handling(char *msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
