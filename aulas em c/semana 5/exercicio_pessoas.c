/*
    Escreva um programa que receba o cadastro de 5 pessoas.
    Cada Pessoa possui Nome, Idade e Telefone.
    O programa deverá escrever na tela o Nome e o telefone da pessoa mais velha.
*/

#include <stdio.h>
#include <string.h>

// Estrutura para representar uma pessoa
struct Pessoa {
    char nome[50];
    int idade;
    char telefone[20];
};

// Função auxiliar para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // Define o número de pessoas a serem cadastradas
    const int NUM_PESSOAS = 5;
    struct Pessoa pessoas[NUM_PESSOAS];
    int i;
    int indiceMaisVelha = 0;

    printf("===== CADASTRO DE PESSOAS =====\n");

    // Loop para receber os dados das 5 pessoas
    for (i = 0; i < NUM_PESSOAS; i++) {
        printf("\n--- Pessoa %d ---\n", i + 1);

        printf("Nome: ");
        // Usa fgets para ler nomes com espaços
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
        // Remove a quebra de linha que o fgets captura
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = 0;

        printf("Idade: ");
        // Valida a entrada da idade
        while (scanf("%d", &pessoas[i].idade) != 1) {
            printf("Entrada inválida. Por favor, digite um número para a idade: ");
            limparBuffer();
        }
        limparBuffer(); // Limpa o buffer após o scanf

        printf("Telefone: ");
        fgets(pessoas[i].telefone, sizeof(pessoas[i].telefone), stdin);
        pessoas[i].telefone[strcspn(pessoas[i].telefone, "\n")] = 0;

        // Verifica se a pessoa atual é a mais velha até agora
        if (pessoas[i].idade > pessoas[indiceMaisVelha].idade) {
            indiceMaisVelha = i;
        }
    }

    // Exibe o telefone da pessoa mais velha
    printf("\nO telefone da pessoa mais velha (%s) é: %s\n", pessoas[indiceMaisVelha].nome, pessoas[indiceMaisVelha].telefone);

    return 0;
}