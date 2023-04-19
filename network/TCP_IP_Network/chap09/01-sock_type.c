#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_socklen_t.h>
#include <unistd.h>
#include <sys/socket.h>

void error_handling(char *msg);

int main(int argc, char *argv[]) {
    int tcp_sock, udp_sock;
    int sock_type;
    socklen_t optlen;
    int state;

    optlen = sizeof(sock_type);
    tcp_sock = socket(PF_INET, SOCK_STREAM, 0);
    udp_sock = socket(PF_INET, SOCK_DGRAM, 0);
    printf("SOCK_STREAM:%d\n", SOCK_STREAM);
    printf("SOCK_DGRAM:%d\n", SOCK_DGRAM);

    state =
        getsockopt(tcp_sock, SOL_SOCKET, SO_TYPE, (void *)&sock_type, &optlen);
    if (state) error_handling("getsockopt() error");
    printf("Socket type one:%d \n", sock_type);
    state =
        getsockopt(udp_sock, SOL_SOCKET, SO_TYPE, (void *)&sock_type, &optlen);
    if (state) error_handling("getsockopt() error");
    printf("Socket type two:%d \n", sock_type);

    /* SOCK_STREAM:1 */
    /* SOCK_DGRAM:2 */
    /* Socket type one:1  */
    /* Socket type two:2  */
    return 0;
}

void error_handling(char *msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
