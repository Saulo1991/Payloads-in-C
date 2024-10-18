#include <stdio.h>
#include <stdlib.h>

void execute_malicious_code() {
    // Código malicioso a ser executado
    printf("Código do atacante executado!\n");
    // Exemplo de um comando malicioso: aqui poderia ser algo como abrir uma backdoor
    system("echo 'Malware ativo' >> /tmp/malware_log.txt");
}

int main() {
    printf("Executando aplicativo legítimo...\n");
    
    // Chama a função que executa código malicioso
    execute_malicious_code();
    
    // Simulando um programa legítimo
    printf("Aplicativo encerrado.\n");
    return 0;
}
