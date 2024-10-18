#include <stdio.h>

int main() {
    printf("Content-Type: text/html\n\n");
    printf("<html><body><h1>Web Shell</h1><pre>");

    // Execute comandos do sistema
    system("ls"); // Executa um comando do sistema

    printf("</pre></body></html>");
    return 0;
}
