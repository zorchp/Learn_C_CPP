#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_endian.h>
#include <sys/_types/_socklen_t.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
const int BUF_SIZE = 30;
void error_handling(char *msg);

int main(int argc, char *argv[]) {
    int serv_sock;
    char msg[BUF_SIZE];
    int str_len, i;
    socklen_t addr_size;
    struct sockaddr_in my_addr, your_addr;

    if (argc != 2) {
        printf("Usage: %s <port> \n", argv[0]);
        exit(1);
    }
    if ((serv_sock = socket(PF_INET, SOCK_DGRAM, 0)) == -1)
        error_handling("UDP socket creation error");

    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    my_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr *)&my_addr, sizeof(my_addr)) == -1)
        error_handling("bind() error");

    for (i = 0; i < 3; ++i) {
        sleep(5);
        addr_size = sizeof(your_addr);
        str_len = recvfrom(serv_sock, msg, BUF_SIZE, 0,
                           (struct sockaddr *)&your_addr, &addr_size);
        printf("msg %d: %s\n", i + 1, msg);
    }
    close(serv_sock);
    return 0;
}

void error_handling(char *msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
