#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/_endian.h>

int main(int argc, char *argv[]) {
    unsigned short host_port = 0x1234;
    unsigned short net_port;

    unsigned long host_addr = 0x12345678;
    unsigned long net_addr;

    net_port = htons(host_port);
    net_addr = htonl(host_addr);

    printf("Host ordered port: %#x \n", host_port);
    printf("Network ordered port: %#x \n", net_port);
    printf("Host ordered address: %#lx \n", host_addr);
    printf("Network ordered address: %#lx \n", net_addr);
    /*little endian
    Host ordered port: 0x1234
    Network ordered port: 0x3412
    Host ordered address: 0x12345678
    Network ordered address: 0x78563412
    */

    return 0;
}
