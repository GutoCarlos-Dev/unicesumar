/*
    Escreva um programa em C que receba 10 idades em um vetor.
    O programa deverá informar qual a idade mais velha.
*/

#include <stdio.h>

int main() {
    int idades[10];
    int i, maior = 0;

    // Entrada das idades
    printf("Digite 10 idades:\n");
    for(i = 0; i < 10; i++) {
        printf("Idade %d: ", i + 1);
        scanf("%d", &idades[i]);

        // Verifica se é a maior idade até agora
        if(idades[i] > maior) {
            maior = idades[i];
        }
    }

    // Exibe a maior idade
    printf("\nA maior idade é: %d\n", maior);

    return 0;
}

/*
Como funciona:
O programa usa um vetor idades[10] para armazenar as idades.

A variável maior guarda a maior idade encontrada durante a leitura.

A cada leitura, ele compara a idade atual com maior e atualiza se necessário.
*/
