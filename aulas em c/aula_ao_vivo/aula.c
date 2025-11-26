#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contato {
      char nome[51];
      char telefone[15];
      char email[50];
      
    };

    int calcularSoma(int num1, int num2) {
        return (num1+num2);
    }

int main(){
    int num1, num2, resultado;
    printf("Digite um numero: ");
    scanf("%d",&num1);
    printf("Digite outro numero: ");
    scanf("%d",&num2);
    
    resultado = calcularSoma(num1, num2);
    printf("A Soma dos numeros eh:  %d", resultado);
    
    return(0);
}