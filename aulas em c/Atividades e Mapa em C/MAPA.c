//MAPA - ADSIS - LINGUAGEM E TÉCNICAS DE PROGRAMAÇÃO - 54_2025

#include <stdio.h>
#include <string.h>

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

    do {
        // Menu principal
        printf("\n===== MENU BIBLIOTECA =====\n");
        printf("1 - Cadastrar livros\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Pesquisar livro por código\n");
        printf("4 - Ordenar livros por ano de publicação\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
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
        getchar(); // Consome o indice 0\n deixado pelo scanf
        printf("Título: ");
        fgets(acervo[i].titulo, 50, stdin);
        strtok(acervo[i].titulo, "\n");
        printf("Autor: ");
        fgets(acervo[i].autor, 30, stdin);
        strtok(acervo[i].autor, "\n");
        printf("Área: ");
        fgets(acervo[i].area, 30, stdin);
        strtok(acervo[i].area, "\n");
        printf("Ano: ");
        scanf("%d", &acervo[i].ano);
        getchar(); // Consome o indice 0\n deixado pelo scanf
        printf("Editora: ");
        fgets(acervo[i].editora, 30, stdin);
        strtok(acervo[i].editora, "\n");
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
