#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#define ERR(x) fprintf(stderr, "%s error \n", #x), exit(-1)

struct sockInfo {
    int fd;
    pthread_t tid;
    struct sockaddr_in addr;
};

// 限定了最大线程数
struct sockInfo sockinfos[128];

void *working(void *arg) { // arg保存了客户端信息
    // 通信逻辑
    struct sockInfo *pinfo = (struct sockInfo *)arg;
    struct sockaddr_in caddr = pinfo->addr;

    int cfd = pinfo->fd;

    char client_IP[16]; // 获取客户端IP
    inet_ntop(AF_INET, &caddr.sin_addr.s_addr, client_IP, sizeof(client_IP));
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
    return NULL;
}

int main(int argc, char *argv[]) {

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

    // init sockinfos
    int max_len = sizeof(sockinfos) / sizeof(sockinfos[0]);
    for (int i = 0; i < max_len; ++i) {
        bzero(&sockinfos[i], sizeof(sockinfos[i]));
        sockinfos[i].fd = -1;
        sockinfos[i].tid = -1;
    }


    // 循环等待客端链接, 一旦一个客户端链接进来, 就创建一个子线程进行通信
    while (1) {
        struct sockaddr_in caddr;
        socklen_t clen = sizeof(caddr); //
        int cfd = accept(lfd, (struct sockaddr *)&caddr, &clen);
        if (cfd == -1) {
            if (errno == EINTR) continue;
            ERR(accept);
        }

        struct sockInfo *pinfo;
        for (int i = 0; i < max_len; ++i) {
            if (sockinfos[i].fd == -1) { // 找到了一个未使用的
                pinfo = &sockinfos[i];
                break;
            }
            if (i == max_len - 1) { // 都用完了, 等
                sleep(1);
                --i;
            }
        }

        pinfo->addr = caddr;
        // memcpy(&pinfo->addr, &caddr, clen);
        pinfo->fd = cfd;
        // printf("addr = %d\n", pinfo->addr.sin_addr.s_addr);

        // 创建子线程
        pthread_create(&pinfo->tid, NULL, working, pinfo);
        // 分离
        pthread_detach(pinfo->tid);
    }
    // 释放服务端套接字
    close(lfd);

    return EXIT_SUCCESS;
}
