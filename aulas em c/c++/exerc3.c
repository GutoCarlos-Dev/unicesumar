/*  Exercicio 3
    Escreva um programa que solicite 2 números para o usuário e
    calcule uma multiplicação entre esses dois números.
*/

#include <stdio.h>

int main() {
    int num1, num2;
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    printf("A multiplicacao entre %d e %d eh: %d\n", num1, num2, num1*num2);
    
    return 0;
}