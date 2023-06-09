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
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) ERR(socket);
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    inet_pton(AF_INET, "59.110.48.22", &saddr.sin_addr.s_addr);
    saddr.sin_port = htons(9006);

    int eno = connect(fd, (struct sockaddr *)&saddr, sizeof(saddr));
    if (eno == -1) ERR(connect);

    // 通信
    char data[] = "I am client\n";
    char recvBuf[1024] = {0};
    while (1) {
        write(fd, data, strlen(data)); // 向服务器写数据
        sleep(1);
        // 读取服务器发送的数据
        int len = read(fd, recvBuf, sizeof(recvBuf));
        if (len == -1)
            ERR(read);
        else if (len > 0)
            printf("recv from server: %s\n", recvBuf);
        else if (len == 0) { // 客户端断开连接
            printf("server closed\n");
            break;
        }
    }

    close(fd);

    return 0;
}
