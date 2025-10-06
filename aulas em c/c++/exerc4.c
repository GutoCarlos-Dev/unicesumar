/*  Exercicio 4
    Escreva um programa que receba o salário de uma pessoa e calcule um aumento de 10%.
*/


#include <stdio.h>
int main(){
    float salario;
    printf("Digite o salario: ");
    scanf("%f", &salario);
    float aumento = salario * 0.10;
    float novo_salario = salario + aumento;
    printf("O novo salario com aumento de 10%% eh: %.2f\n", novo_salario);
    return 0;
}