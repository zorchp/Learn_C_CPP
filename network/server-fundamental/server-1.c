#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
// #include <sys/socket.h>
// #include <sys/types.h>
#include <arpa/inet.h> // 等价于上面两个
#include <string.h>

// 错误记录
#define ERR(x) perror(#x), exit(-1)

int main(int argc, char *argv[]) {
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1) ERR(socket);

    struct sockaddr_in saddr;
    saddr.sin_family = PF_INET;
    inet_pton(AF_INET, "127.0.0.1", &saddr.sin_addr.s_addr);
    // saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(9999);

    int eno = bind(lfd, (struct sockaddr *)&saddr, sizeof(saddr));
    if (eno == -1) ERR(bind);

    eno = listen(lfd, 8);
    if (eno == -1) ERR(listen);

    // 接受客户端连接: 阻塞 Accept
    struct sockaddr_in caddr;
    socklen_t slen = sizeof(caddr);
    int cfd = accept(lfd, (struct sockaddr *)&caddr, &slen);
    if (cfd == -1) ERR(accept);

    // 输出客户端信息
    char client_IP[16];
    inet_ntop(AF_INET, &caddr.sin_addr.s_addr, client_IP, sizeof(client_IP));
    unsigned short client_Port = ntohs(caddr.sin_port);

    printf("client IP is %s, port is %d\n", client_IP, client_Port);


    char recvBuf[1024] = {0};
    while (1) {
        // 获取客户端数据
        int len = read(cfd, recvBuf, sizeof(recvBuf));
        if (len == -1)
            ERR(read);
        else if (len > 0)
            printf("recv from client: %s\n", recvBuf);
        else if (len == 0) { // 客户端断开连接
            printf("client closed\n");
            break;
        }

        // 发数据
        char data[] = "hello I am server\n";
        write(cfd, data, strlen(data));
    }
    close(lfd);
    close(cfd);

    return EXIT_SUCCESS;
}
