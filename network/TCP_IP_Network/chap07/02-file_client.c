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
    int sd;
    char buf[BUF_SIZE];
    int read_cnt;
    FILE *fp;
    struct sockaddr_in serv_addr;

    if (argc != 3) {
        printf("Usage: %s <IP> <port> \n", argv[0]);
        exit(1);
    }

    fp = fopen("receive.txt", "wb");
    sd = socket(PF_INET, SOCK_STREAM, 0);
    if (sd == -1) error_handling("UDP socket creation error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error");

    while ((read_cnt = read(sd, buf, BUF_SIZE)) != 0)
        fwrite((void *)buf, 1, read_cnt, fp);

    printf("Received fiel data.\n");
    write(sd, "thank you", 10);

    fclose(fp);
    close(sd);
    return 0;
}

void error_handling(char *msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
