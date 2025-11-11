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
int cadastrarLivros(struct Livro acervo[], int livrosJaCadastrados, int tamanhoMaximo);
void imprimirLivros(struct Livro acervo[], int livrosCadastrados);
void pesquisarLivro(struct Livro acervo[], int livrosCadastrados, int codigoBusca);
void ordenarLivros(struct Livro acervo[], int livrosCadastrados);

int main() {
    struct Livro acervo[TAMANHO_ACERVO] = {0}; // Inicializa o acervo com zeros
    int opcao, codigoBusca, livrosCadastrados = 0;

    do {
        // Menu principal
        printf("\n===== MENU BIBLIOTECA =====\n");
        printf("1 - Cadastrar livros\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Pesquisar livro por código\n");
        printf("4 - Ordenar livros por ano de publicação\n");
        printf("5 - Sair\n");
        printf("Livros cadastrados: %d de %d\n", livrosCadastrados, TAMANHO_ACERVO);
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                livrosCadastrados = cadastrarLivros(acervo, livrosCadastrados, TAMANHO_ACERVO);
                break;
            case 2:
                imprimirLivros(acervo, livrosCadastrados);
                break;
            case 3:
                printf("Digite o código do livro: ");
                if (scanf("%d", &codigoBusca) == 1) {
                    pesquisarLivro(acervo, livrosCadastrados, codigoBusca);
                }
                break;
            case 4:
                ordenarLivros(acervo, livrosCadastrados);
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
int cadastrarLivros(struct Livro acervo[], int livrosJaCadastrados, int tamanhoMaximo) {
    int i = livrosJaCadastrados;
    char continuar;

    if (i >= tamanhoMaximo) {
        printf("\nAcervo cheio! Não é possível cadastrar mais livros.\n");
        return i;
    }

    while (i < tamanhoMaximo) {
        printf("\nCadastro do Livro %d:\n", i + 1);
        printf("Código: ");
        scanf("%d", &acervo[i].codigo);
        getchar(); // Consome o newline deixado pelo scanf
        printf("Título: ");
        fgets(acervo[i].titulo, sizeof(acervo[i].titulo), stdin);
        strtok(acervo[i].titulo, "\n");
        printf("Autor: ");
        fgets(acervo[i].autor, sizeof(acervo[i].autor), stdin);
        strtok(acervo[i].autor, "\n");
        printf("Área: ");
        fgets(acervo[i].area, sizeof(acervo[i].area), stdin);
        strtok(acervo[i].area, "\n");
        printf("Ano: ");
        scanf("%d", &acervo[i].ano);
        getchar(); // Consome o newline deixado pelo scanf
        printf("Editora: ");
        fgets(acervo[i].editora, sizeof(acervo[i].editora), stdin);
        strtok(acervo[i].editora, "\n");
        i++;
        if (i < tamanhoMaximo) {
            printf("\nDeseja cadastrar outro livro? (s/n): ");
            scanf("%c", &continuar);
            getchar(); // Consome o newline
            if (continuar != 's' && continuar != 'S') {
                break;
            }
        } else {
            printf("\nAcervo cheio!\n");
        }
    }
    return i; // Retorna o novo número de livros cadastrados
}

// Função para imprimir todos os livros
void imprimirLivros(struct Livro acervo[], int livrosCadastrados) {
    printf("\n===== LISTA DE LIVROS =====\n");
    if (livrosCadastrados == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    for (int i = 0; i < livrosCadastrados; i++) {
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
void pesquisarLivro(struct Livro acervo[], int livrosCadastrados, int codigoBusca) {
    int encontrado = 0;
    if (livrosCadastrados == 0) {
        printf("Nenhum livro cadastrado para pesquisar.\n");
        return;
    }

    for (int i = 0; i < livrosCadastrados; i++) {
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
void ordenarLivros(struct Livro acervo[], int livrosCadastrados) {
    struct Livro temp;
    if (livrosCadastrados < 2) {
        printf("É necessário ter pelo menos 2 livros para ordenar.\n");
        return;
    }
    for (int i = 0; i < livrosCadastrados - 1; i++) {
        for (int j = 0; j < livrosCadastrados - i - 1; j++) {
            if (acervo[j].ano > acervo[j + 1].ano) {
                temp = acervo[j];
                acervo[j] = acervo[j + 1];
                acervo[j + 1] = temp;
            }
        }
    }
}
