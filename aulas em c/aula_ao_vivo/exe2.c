#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAMANHO_ACERVO 20

struct Livro {
    int codigo;
    char titulo[50];
    char autor[30];
    char area[30];
    int ano;
    char editora[30];
};

void cadastrarLivros(struct Livro acervo[], int tamanho);
void imprimirLivros(struct Livro acervo[], int tamanho);
void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca);
void ordenarLivros(struct Livro acervo[], int tamanho);

int main() {
    struct Livro acervo[TAMANHO_ACERVO];
    int opcao, codigoBusca;

    setlocale(LC_ALL, "Portuguese_Brazil.utf8");
    
    do {
        printf("\n====Menu - Sistema de Gerenciamento de Livros====\n");
        printf("1 - Cadastrar livros\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Pesquisar livro por codigo\n");
        printf("4 - Ordenar livros por ano de publicacao\n");
        printf("5 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao) {
            case 1:
                cadastrarLivros(acervo, TAMANHO_ACERVO);
                break;
            case 2:
                imprimirLivros(acervo, TAMANHO_ACERVO);
                break;
            case 3:
                printf("Informe o codigo do livro a ser pesquisado: ");
                scanf("%d", &codigoBusca);
                fflush(stdin);
                pesquisarLivro(acervo, TAMANHO_ACERVO, codigoBusca);
                break;
            case 4:
                ordenarLivros(acervo, TAMANHO_ACERVO);
                printf("Livros ordenados por ano de publicação.\n");
                break;
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida, tente novamente.\n");
                break;
        }
    } while(opcao != 5);

    return 0;
}

// Função para cadastrar livros no acervo
void cadastrarLivros(struct Livro acervo[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("\nCadastro do livro %d\n", i+1);
        printf("Codigo: ");
        scanf("%d", &acervo[i].codigo);
        fflush(stdin);
        printf("Titulo: ");
        fgets(acervo[i].titulo, sizeof(acervo[i].titulo), stdin);
        acervo[i].titulo[strcspn(acervo[i].titulo, "\n")] = '\0';  // Remove newline
        printf("Autor: ");
        fgets(acervo[i].autor, sizeof(acervo[i].autor), stdin);
        acervo[i].autor[strcspn(acervo[i].autor, "\n")] = '\0';
        printf("Area: ");
        fgets(acervo[i].area, sizeof(acervo[i].area), stdin);
        acervo[i].area[strcspn(acervo[i].area, "\n")] = '\0';
        printf("Ano: ");
        scanf("%d", &acervo[i].ano);
        fflush(stdin);
        printf("Editora: ");
        fgets(acervo[i].editora, sizeof(acervo[i].editora), stdin);
        acervo[i].editora[strcspn(acervo[i].editora, "\n")] = '\0';
    }
    printf("\nCadastro concluido.\n");
}

// Função para imprimir os livros cadastrados
void imprimirLivros(struct Livro acervo[], int tamanho) {
    printf("\nLista de livros cadastrados:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("\nLivro %d:\n", i+1);
        printf("Codigo: %d\n", acervo[i].codigo);
        printf("Titulo: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Area: %s\n", acervo[i].area);
        printf("Ano: %d\n", acervo[i].ano);
        printf("Editora: %s\n", acervo[i].editora);
    }
}

// Função para pesquisar livro por código
void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca) {
    int encontrado = 0;
    for(int i = 0; i < tamanho; i++) {
        if(acervo[i].codigo == codigoBusca) {
            printf("\nLivro encontrado:\n");
            printf("Codigo: %d\n", acervo[i].codigo);
            printf("Titulo: %s\n", acervo[i].titulo);
            printf("Autor: %s\n", acervo[i].autor);
            printf("Area: %s\n", acervo[i].area);
            printf("Ano: %d\n", acervo[i].ano);
            printf("Editora: %s\n", acervo[i].editora);
            encontrado = 1;
            break;
        }
    }
    if(!encontrado) {
        printf("Livro com codigo %d nao encontrado.\n", codigoBusca);
    }
}

// Função para ordenar livros pelo ano de publicação usando Bubble Sort
void ordenarLivros(struct Livro acervo[], int tamanho) {
    struct Livro temp;
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; j < tamanho - i - 1; j++) {
            if(acervo[j].ano > acervo[j+1].ano) {
                temp = acervo[j];
                acervo[j] = acervo[j+1];
                acervo[j+1] = temp;
            }
        }
    }
}
