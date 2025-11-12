/*
    Escreva um programa em linguagem C que receba 2 notas de 5 alunos.
    Essas notas devem ser armazenadas em uma matriz onde cada linha representa um aluno
    e cada coluna representa uma nota.

    O programa deverá exibir na tela a média de cada aluno e informar se ele está aprovado (média > 7),
    em recuperação (média entre 6 e 7), reprovado (média < 6).
*/

#include <stdio.h>

int main() {
    float notas[5][2]; // Matriz para armazenar 2 notas de 5 alunos
    float media;
    int i, j;

    // Entrada das notas
    for(i = 0; i < 5; i++) {
        printf("Aluno %d:\n", i + 1);
        for(j = 0; j < 2; j++) {
            printf("  Nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    // Cálculo da média e exibição do resultado
    printf("\nResultados:\n");
    for(i = 0; i < 5; i++) {
        media = (notas[i][0] + notas[i][1]) / 2;
        printf("Aluno %d - Média: %.2f - ", i + 1, media);

        if(media > 7) {
            printf("Aprovado\n");
        } else if(media >= 6 && media <= 7) {
            printf("Em recuperação\n");
        } else {
            printf("Reprovado\n");
        }
    }

    return 0;
}

/*
O que esse programa faz:
Recebe 2 notas para cada um dos 5 alunos.

Calcula a média de cada aluno.

Exibe se o aluno está aprovado, em recuperação ou reprovado, com base na média.
*/
