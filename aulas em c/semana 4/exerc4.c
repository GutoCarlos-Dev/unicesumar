/*
    DESAFIO!!!

    Escreva um programa em C que receba 5 números inteiros em um vetor.
    O programa deverá exibir na tela os 5 números em ordem crescente.

    Exemplo:
    Recebe: 10 6 7 2 8
    Escreve: 2 6 7 8 10

    DICA: Pesquisem sobre Bubble Sort.
*/

#include <stdio.h>

int main() {
    int numeros[5];
    int i, j, aux;

    // Recebe os 5 números
    printf("Digite 5 numeros inteiros:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &numeros[i]);
    }
    

    // Ordena os números usando o método da bolha (bubble sort)
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (numeros[i] > numeros[j]) {
                aux = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = aux;
            }
        }
    }

    // ok Exibe os números em ordem crescente
    printf("Números em ordem crescente:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
