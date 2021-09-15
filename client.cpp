#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
//    The UDP socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
//    If the program cannot open a socket, raise an error and stop.
    if (sock < 0) {
        perror("Cannot open socket");
        return(-1);
    }
//    Start scanning ports from this port number
    int from = 4000;
//    Until (inclusive) this port number
    int to = 4100;
    char* dest_ip = "".c_str();

    char buffer[1400];
    struct sockaddr_in destaddr;
//    The msg in the buffer
    strcpy(buffer, "Hey Port");

    int length = strlen(buffer) + 1;

    destaddr.sin_family = AF_INET;
    inet_aton(dest_ip, &destaddr.sin_addr);

//    Loop over all requested port numbers
    for (int port_no = from; port_no <= to; port_no++) {
        destaddr.sin_port = htons(port_no);

        if (sendto(sock, buffer, length, 0, (const struct  sockaddr *)&destaddr, sizeof(destaddr)) < 0) {
            perror("Could not send")
        }
    }
}