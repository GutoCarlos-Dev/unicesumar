/*
    Escreva um programa que controle o estoque de uma loja.
    Essa loja pode possuir AT√â 50 produtos.
    Cada produto possui:
        - Nome
        - cÛdigo
        - Pre√ßo
        - Quantidade em estoque
    
    O programa deve permitir:
        1. Cadastrar novo produto
        2. Pesquisar um produto pela matricula
        3. Reduzir a quantidade em estoque de um produto
        4. Listar todos os produtos
        5. Sair
    
    O programa s√≥ poder√° ser encerrado quando o usu√°rio escolher a op√ß√£o 5.
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_PRODUTOS 50

struct Produto {
    char nome[30];
    int cod, qtd;
    float preco;
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct Produto produtos[MAX_PRODUTOS];
    int opcao, num_produtos = 0, cod_busca, qtd_reduzir, i, encontrado;

    do {
        printf("\n--- CONTROLE DE ESTOQUE ---\n");
        printf("Produtos cadastrados: %d de %d\n", num_produtos, MAX_PRODUTOS);
        printf("Escolha uma opÁ„o:\n");
        printf("[1] Cadastrar Produto\n");
        printf("[2] Pesquisar Produto por CÛdigo\n");
        printf("[3] Reduzir Estoque de Produto\n");
        printf("[4] Listar Todos os Produtos\n");
        printf("[5] Sair\n");
        printf("OpÁ„o: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                if (num_produtos >= MAX_PRODUTOS) {
                    printf("Erro: Estoque cheio. N√O … possÕvel cadastrar mais produtos.\n");
                } else {
                    printf("\n--- Cadastro de Produto ---\n");
                    printf("CÛdigo: ");
                    scanf("%d", &produtos[num_produtos].cod);
                    getchar();

                    printf("Nome: ");
                    fgets(produtos[num_produtos].nome, 30, stdin);
                    produtos[num_produtos].nome[strcspn(produtos[num_produtos].nome, "\n")] = '\0'; // Remove o \n

                    printf("PreÁo: ");
                    scanf("%f", &produtos[num_produtos].preco);

                    printf("Quantidade em estoque: ");
                    scanf("%d", &produtos[num_produtos].qtd);

                    printf("Produto '%s' cadastrado com sucesso!\n", produtos[num_produtos].nome);
                    num_produtos++;
                }
                break;
            case 2:
                printf("\nDigite o cÛdigo do produto a ser pesquisado: ");
                scanf("%d", &cod_busca);
                encontrado = 0;
                for (i = 0; i < num_produtos; i++) {
                    if (produtos[i].cod == cod_busca) {
                        printf("\n--- Produto Encontrado ---\n");
                        printf("CÛdigo: %d\n", produtos[i].cod);
                        printf("Nome: %s\n", produtos[i].nome);
                        printf("PreÁoo: R$ %.2f\n", produtos[i].preco);
                        printf("Quantidade em Estoque: %d\n", produtos[i].qtd);
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Produto com cÛdigo %d n√£o encontrado.\n", cod_busca);
                }
                break;
            case 3:
                printf("\nDigite o cÛdigo do produto para reduzir o estoque: ");
                scanf("%d", &cod_busca);
                encontrado = 0;
                for (i = 0; i < num_produtos; i++) {
                    if (produtos[i].cod == cod_busca) {
                        printf("Produto: %s | Estoque atual: %d\n", produtos[i].nome, produtos[i].qtd);
                        printf("Digite a quantidade a ser removida: ");
                        scanf("%d", &qtd_reduzir);

                        if (qtd_reduzir > 0 && qtd_reduzir <= produtos[i].qtd) {
                            produtos[i].qtd -= qtd_reduzir;
                            printf("Estoque atualizado: %d\n", produtos[i].qtd);
                        } else {
                            printf("Quantidade inv√°lida ou insuficiente em estoque.\n");
                        }
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Produto com cÛdigo %d n√£o encontrado.\n", cod_busca);
                }
                break;
            case 4:
                if (num_produtos == 0) {
                    printf("\nNenhum produto cadastrado.\n");
                } else {
                    printf("\n--- Lista de Todos os Produtos ---\n");
                    for (i = 0; i < num_produtos; i++) {
                        printf("----------------------------------\n");
                        printf("Produto %d\n", i + 1);
                        printf("cÛdigo: %d\n", produtos[i].cod);
                        printf("Nome: %s\n", produtos[i].nome);
                        printf("Pre√ßo: R$ %.2f\n", produtos[i].preco);
                        printf("Quantidade em Estoque: %d\n", produtos[i].qtd);
                    }
                }
                break;
            case 5:
                printf("At√© logo.\n");
                break;
            default:
                printf("Op√ß√£o inv√°lida. Tente novamente.\n");
                break;
        }
    } while(opcao != 5);

    return 0;
}