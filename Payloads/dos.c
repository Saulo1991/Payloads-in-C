#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    while(1) {
        // Loop infinito que consome CPU
        printf("Ataque DoS em andamento...\n");
        fflush(stdout); // Garante que a saída seja exibida imediatamente
        sleep(1);       // Espera 1 segundo antes de imprimir novamente
    }
    return 0;
}
