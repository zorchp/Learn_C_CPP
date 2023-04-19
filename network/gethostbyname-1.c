#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    struct hostent *h;
    char **pp;
    char str[INET6_ADDRSTRLEN];
    char *argvv[3];
    argvv[0] = "www.baidu.com";
    argvv[1] = "www.qq.com";
    argvv[2] = NULL;
    for (char **rp = argvv; *rp != NULL; ++rp) {
        sleep(1);
        h = gethostbyname(*rp);
        if (h == NULL) {
            fprintf(stderr, "gethostname error, %s, %s\n", *rp,
                    hstrerror(h_errno));
            continue;
        }

        printf("Canonical name %s\n", h->h_name);

        printf("alias :\n");
        for (pp = h->h_aliases; *pp != NULL; ++pp) printf("%s\n", *pp);
        putchar('\n');

        printf("address type: \n");
        switch (h->h_addrtype) {
            case AF_INET:
                printf("AF_INET\n");
                for (pp = h->h_addr_list; *pp != NULL; ++pp)
                    printf("%s\n", inet_ntop(h->h_addrtype, *pp, str,
                                             INET6_ADDRSTRLEN));
                break;
            case AF_INET6:
                printf("AF_INET6\n");
                for (pp = h->h_addr_list; *pp != NULL; ++pp)
                    printf("%s\n", inet_ntop(h->h_addrtype, *pp, str,
                                             INET6_ADDRSTRLEN));
                break;
            default:
                printf("???\n");
        }
    }
    return 0;
}
/*
Canonical name www.a.shifen.com
alias :
www.baidu.com

address type:
AF_INET
182.61.200.7
182.61.200.6
Canonical name ins-r23tsuuf.ias.tencent-cloud.net
alias :
www.qq.com

address type:
AF_INET
175.27.8.138
*/
