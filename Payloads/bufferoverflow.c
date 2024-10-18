#include <stdio.h>
#include <string.h>

void secret_function() {
    printf("Você acessou a função secreta!\n");
}

void vulnerable_function() {
    char buffer[64];
    printf("Digite algo: ");
    gets(buffer); // Vulnerabilidade de buffer overflow
}

int main() {
    vulnerable_function();
    return 0;
}
