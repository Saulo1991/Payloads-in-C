// Implemente uma função em C que receba dois ponteiros para inteiros, troque os valores apontados
// por eles e retorne o maior valor através de um terceiro ponteiro.

// 1. var1, var2, ptr1, ptr2
// 2. Receber dois ponteiros, trocar os valores apontados por eles e retornar o maior valor

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1 = 10;
    int n2 = 5;
    int *ptr1,*ptr2;

    ptr1 = &n1;
    ptr2 = &n2;

    *ptr1 = *ptr1 + *ptr2;
    *ptr2 = *ptr1 - *ptr2;
    *ptr1 = *ptr1 - *ptr2;

    if (*ptr1 > *ptr2) {
        printf("Greater ptr1: %d", *ptr1);
    } else {
        printf("Greater ptr2: %d", *ptr2);
    }

    return 0;
}