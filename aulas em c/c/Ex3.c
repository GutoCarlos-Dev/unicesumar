/*
    DESAFIO!!!

    Escreva um programa em C que receba 5 números inteiros em um vetor.
    O programa deverá exibir na tela os 5 números em ordem crescente.

    Exemplo:
    Recebe: 10 6 7 2 8
    Escreve: 2 6 7 8 10
*/

#include <stdio.h>

int main() {
    int numeros[5];
    int i, j, temp;

    // Entrada dos números
    printf("Digite 5 números inteiros:\n");
    for(i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Ordenação (método da bolha - Bubble Sort)
    for(i = 0; i < 4; i++) {
        for(j = i + 1; j < 5; j++) {
            if(numeros[i] > numeros[j]) {
                temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }

    // Exibição dos números ordenados
    printf("\nNúmeros em ordem crescente:\n");
    for(i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}

/*
Como funciona:
Lê 5 números do usuário.

Usa o algoritmo Bubble Sort para ordenar.

Exibe os números em ordem crescente.

*/