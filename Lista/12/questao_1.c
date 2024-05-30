/*
1. Escreva uma função recursiva que recebe um número inteiro positivo e retorna a soma dos dígitos do número.

Aluno: Matheus Almeida Silva - 316326
*/

#include <stdio.h>
#include <stdlib.h>

int soma_recursiva(int n){          //Funcao recursiva que recebe o inteiro e soma seus digitos
    if (n < 10)
        return n;              //Caso o numero seja menor que 10, retorna o numero. Condicao de parada.
    else
        return n % 10 + soma_recursiva ((n - n % 10)/10);    //Do contrário retorna a soma do resto de 10(ultimo algarismo) com funcao recursiva desse numero menos seu ultimo algarismo
    

}

int main (){
    int n;
    printf("Insira o numero: ");
    scanf("%d", &n);
    printf("A soma dos digitos do numero eh: %d", soma_recursiva(n));

    return 0;
}