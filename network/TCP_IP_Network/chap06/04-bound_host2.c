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
    int sock;
    char m1[] = "nihao1";
    char m2[] = "nihao2";
    char m3[] = "nihao3";
    /* socklen_t addr_size; */
    struct sockaddr_in your_addr;

    if (argc != 3) {
        printf("Usage: %s <IP> <port> \n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1) error_handling("UDP socket creation error");

    memset(&your_addr, 0, sizeof(your_addr));
    your_addr.sin_family = AF_INET;
    your_addr.sin_addr.s_addr = inet_addr(argv[1]);
    your_addr.sin_port = htons(atoi(argv[2]));

    sendto(sock, m1, strlen(m1), 0, (struct sockaddr *)&your_addr,
           sizeof(your_addr));
    sendto(sock, m2, strlen(m2), 0, (struct sockaddr *)&your_addr,
           sizeof(your_addr));
    sendto(sock, m3, strlen(m3), 0, (struct sockaddr *)&your_addr,
           sizeof(your_addr));
    close(sock);
    return 0;
}

void error_handling(char *msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
