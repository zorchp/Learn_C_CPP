#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_endian.h>
#include <sys/_types/_socklen_t.h>
#include <sys/unistd.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
const int BUF_SIZE = 30;
void error_handling(char *msg);

int main(int argc, char *argv[]) {
    int serv_sd, clnt_sd;
    char buf[BUF_SIZE];
    int read_cnt;
    FILE *fp;
    socklen_t clnt_addr_size;
    struct sockaddr_in serv_addr, clnt_addr;

    if (argc != 2) {
        printf("Usage: %s <port> \n", argv[0]);
        exit(1);
    }

    fp = fopen("01-file_server.c", "rb");
    serv_sd = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sd == -1) error_handling("UDP socket creation error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");

    listen(serv_sd, 5);

    clnt_addr_size = sizeof(clnt_addr);
    clnt_sd = accept(serv_sd, (struct sockaddr *)&clnt_addr, &clnt_addr_size);

    while (1) {
        read_cnt = fread((void *)buf, 1, BUF_SIZE, fp);
        if (read_cnt < BUF_SIZE) {
            write(clnt_sd, buf, read_cnt);
            break;
        }
        write(clnt_sd, buf, BUF_SIZE);
    }

    // half-close
    shutdown(clnt_sd, SHUT_WR);
    read(clnt_sd, buf, BUF_SIZE);
    printf("msg from client: %s\n", buf);
    fclose(fp);
    close(serv_sd);
    close(clnt_sd);
    return 0;
}

void error_handling(char *msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
