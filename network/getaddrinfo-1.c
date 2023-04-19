#include <arpa/inet.h>
#include <assert.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    struct addrinfo hints1, *res1, *rp;
    memset(&hints1, 0, sizeof(hints1));

    char* hostname = "www.dlut.edu.cn";
    char* port = NULL;
    char str[INET6_ADDRSTRLEN];


    assert(getaddrinfo(hostname, port, &hints1, &res1) == 0);

    for (rp = res1; rp != NULL; rp = rp->ai_next) {
        printf("%d\n", rp->ai_flags);
        printf("%d\n", rp->ai_family);
        printf("%d\n", rp->ai_socktype);
        printf("%d\n", rp->ai_protocol);
        printf("%u\n", rp->ai_addrlen);
        printf("%s\n", rp->ai_canonname); // 空值
        printf("%s\n", inet_ntop(rp->ai_addr->sa_family, hostname, str,
                                 INET6_ADDRSTRLEN));

        printf("%s\n", rp->ai_addr->sa_data);
        printf("%u\n", rp->ai_addr->sa_family);
    }
    freeaddrinfo(rp);
    return 0;
}
