#include <arpa/inet.h>
#include <assert.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int ret;
    struct addrinfo hints;
    struct addrinfo *res;
    struct addrinfo *p;

    bzero(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;     // IPV4 or IPV6
    hints.ai_socktype = SOCK_STREAM; // TCP
    hints.ai_flags = AI_CANONNAME;

    if ((ret = getaddrinfo("216.58.221.36", NULL, &hints, &res)) != 0) { // here
        exit(-1);
    }
    p = res;
    printf("%s\n", p->ai_canonname);
    return 0;
}