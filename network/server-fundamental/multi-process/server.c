#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <wait.h>
#include <errno.h>
#include <signal.h>

#define ERR(x) fprintf(stderr, "%s error \n", #x), exit(-1)

void recycleChild(int arg) {
    while (1) {
        int ans = waitpid(-1, NULL, WNOHANG);
        if (ans == -1)
            break;
        else if (ans == 0)
            break;
        else if (ans > 0) {
            printf("child pid: %d recycled \n", ans);
        }
    }
}

int main(int argc, char *argv[]) {

    struct sigaction act;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    act.sa_handler = recycleChild;
    // 注册信号捕捉
    sigaction(SIGCHLD, &act, NULL);

    // create socket
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1) ERR(socket);

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9006);
    saddr.sin_addr.s_addr = INADDR_ANY; // 0.0.0.0 default all addr

    int err = bind(lfd, (struct sockaddr *)&saddr, sizeof(saddr));
    if (err == -1) ERR(bind);

    err = listen(lfd, 128);
    if (err == -1) ERR(listen);


    while (1) {
        struct sockaddr_in caddr;
        socklen_t clen = sizeof(caddr); //
        int cfd = accept(lfd, (struct sockaddr *)&caddr, &clen);
        if (cfd == -1) {
            if (errno == EINTR) continue;
            ERR(accept);
        }

        pid_t pid = fork();
        if (pid == 0) {         // 子进程
            char client_IP[16]; // 获取客户端IP
            inet_ntop(AF_INET, &caddr.sin_addr.s_addr, client_IP,
                      sizeof(client_IP));
            unsigned short client_Port = ntohs(caddr.sin_port);
            printf("client ip=%s, port=%d\n", client_IP, client_Port);
            char recvBuf[1024];
            while (1) {
                int len = read(cfd, &recvBuf, sizeof(recvBuf));
                if (len == -1) {
                    // printf("errno=%d\n", errno);
                    if (errno == ECONNRESET) continue;
                    ERR(read);
                } else if (len > 0)
                    printf("recv client data : %s", recvBuf);
                else if (len == 0) {
                    printf("client closed...\n");
                    break;
                }
                // 写回客户端
                write(cfd, recvBuf, 1 + strlen(recvBuf));
            }
            close(cfd);
            // 退出子进程
            exit(0);
        } else if (pid == -1)
            ERR(fork);
    }
    // 释放服务端套接字
    close(lfd);

    return EXIT_SUCCESS;
}
