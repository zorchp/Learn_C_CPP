#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_endian.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

const int BUF_SIZE = 1024;
const int OPSZ = 4;

int calc(int opnum, int opnds[], char op);
void error_handling(char *opinfo);

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;

    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;

    char opinfo[BUF_SIZE];
    int res, op_cnt, i;
    int recv_len, recv_cnt;

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
        op_cnt = 0;
        clnt_sock =
            accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
        if (clnt_sock == -1)
            error_handling("accept() error");
        else
            printf("Connected client %d \n", i + 1);

        read(clnt_sock, &op_cnt, 1);

        recv_len = 0;

        while ((op_cnt * OPSZ + 1) > recv_len) {
            recv_cnt = read(clnt_sock, &opinfo[recv_len], BUF_SIZE - 1);
            recv_len += recv_cnt;
        }

        res = calc(op_cnt, (int *)opinfo, opinfo[recv_len - 1]);
        write(clnt_sock, (char *)&res, sizeof(res));
        printf("Disconnected client %d \n", i + 1);
        close(clnt_sock);
    }
    printf("Close server\n");
    close(serv_sock);

    return 0;
}

int calc(int opnum, int opnds[], char op) {
    int result = opnds[0], i;
    printf("opnum=%d\n", opnum);
    printf("op=%c\n", op);
    for (i = 0; i < opnum; i++) printf("opnds[%d]=%d", i, opnds[i]);
    putchar('\n');
    switch (op) {
        case '+':
            for (i = 1; i < opnum; i++) result += opnds[i];
            break;
        case '-':
            for (i = 1; i < opnum; i++) result -= opnds[i];
            break;
        case '*':
            for (i = 1; i < opnum; i++) result *= opnds[i];
            break;
    }
    return result;
}

void error_handling(char *opinfo) {
    fputs(opinfo, stderr);
    fputc('\n', stderr);
    exit(1);
}
