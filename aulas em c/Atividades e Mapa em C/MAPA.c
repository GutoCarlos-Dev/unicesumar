//MAPA - ADSIS - LINGUAGEM E TÉCNICAS DE PROGRAMAÇÃO - 54_2025

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define TAMANHO_ACERVO 20 // Constante que define o tamanho máximo do acervo

// Estrutura que representa um livro
struct Livro {
    int codigo;
    char titulo[50];
    char autor[30];
    char area[30];
    int ano;
    char editora[30];
};

// Funções principais do sistema
void cadastrarLivros(struct Livro acervo[], int tamanho, int *numLivros);
void imprimirLivros(struct Livro acervo[], int tamanho);
void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca);
void ordenarLivros(struct Livro acervo[], int tamanho);

int main() {
    struct Livro acervo[TAMANHO_ACERVO];
    int opcao, codigoBusca;
    int numLivros = 0; // Contador de livros cadastrados

    // Configura o console para aceitar caracteres UTF-8 (alternativa mais robusta)
    system("chcp 65001 > nul");

    setlocale(LC_ALL, "Portuguese");

    do {
        // Menu principal
        printf("\n===== MENU BIBLIOTECA =====\n");
        printf("1 - Cadastrar livros\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Pesquisar livro por codigo\n");
        printf("4 - Ordenar livros por ano de publicacao\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarLivros(acervo, TAMANHO_ACERVO, &numLivros);
                break;
            case 2:
                imprimirLivros(acervo, numLivros);
                break;
            case 3:
                printf("Digite o código do livro: ");
                scanf("%d", &codigoBusca);
                pesquisarLivro(acervo, numLivros, codigoBusca);
                break;
            case 4:
                ordenarLivros(acervo, numLivros);
                printf("Livros ordenados por ano!\n");
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 5);

    return 0;
}

// Função para cadastrar livros
void cadastrarLivros(struct Livro acervo[], int tamanho, int *numLivros) {
    int i = *numLivros;
    char continuar;
    while (i < tamanho) {
        printf("\nCadastro do Livro %d:\n", i + 1);
        printf("Código: ");
        scanf("%d", &acervo[i].codigo);
        while (getchar() != '\n'); // Limpa o buffer de entrada
        printf("Título: ");
        fgets(acervo[i].titulo, 50, stdin);
        acervo[i].titulo[strcspn(acervo[i].titulo, "\n")] = 0;
        printf("Autor: ");
        fgets(acervo[i].autor, 30, stdin);
        acervo[i].autor[strcspn(acervo[i].autor, "\n")] = 0;
        printf("Área: ");
        fgets(acervo[i].area, 30, stdin);
        acervo[i].area[strcspn(acervo[i].area, "\n")] = 0;
        printf("Ano: ");
        scanf("%d", &acervo[i].ano);
        while (getchar() != '\n'); // Limpa o buffer de entrada
        printf("Editora: ");
        fgets(acervo[i].editora, 30, stdin);
        acervo[i].editora[strcspn(acervo[i].editora, "\n")] = 0;
        (*numLivros)++;
        i++;
        if (i < tamanho) {
            printf("\nDeseja cadastrar outro livro? (s/n): ");
            scanf("%c", &continuar);
            getchar(); // Consome o indice 0\n deixado pelo scanf
            if (continuar != 's' && continuar != 'S') {
                break;
            }
        }
    }
}

// Função para imprimir todos os livros
void imprimirLivros(struct Livro acervo[], int tamanho) {
    if (tamanho == 0) {
        printf("\nNenhum livro cadastrado.\n");
        return;
    }

    printf("\n===== LISTA DE LIVROS =====\n");
    for (int i = 0; i < tamanho; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Código: %d\n", acervo[i].codigo);
        printf("Título: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Área: %s\n", acervo[i].area);
        printf("Ano: %d\n", acervo[i].ano);
        printf("Editora: %s\n", acervo[i].editora);
    }
}

// Função para pesquisar livro por código
void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca) {
    if (tamanho == 0) {
        printf("\nNenhum livro cadastrado para pesquisar.\n");
        return;
    }

    int encontrado = 0;
    for (int i = 0; i < tamanho; i++) {
        if (acervo[i].codigo == codigoBusca) {
            printf("\nLivro encontrado:\n");
            printf("Título: %s\n", acervo[i].titulo);
            printf("Autor: %s\n", acervo[i].autor);
            printf("Área: %s\n", acervo[i].area);
            printf("Ano: %d\n", acervo[i].ano);
            printf("Editora: %s\n", acervo[i].editora);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Livro com código %d não encontrado.\n", codigoBusca);
    }
}

// Função para ordenar livros por ano de publicação (Bubble Sort)
void ordenarLivros(struct Livro acervo[], int tamanho) {
    if (tamanho < 2) {
        // Não há o que ordenar
        return;
    }

    struct Livro temp;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (acervo[j].ano > acervo[j + 1].ano) {
                temp = acervo[j];
                acervo[j] = acervo[j + 1];
                acervo[j + 1] = temp;
            }
        }
    }
}
