/*
2. (0,3 pontos a mais na média). Faça um programa que lê um número inteiro N>1 do teclado e imprime (sem repetir) todas as combinações de números 
(maiores ou iguais que 2) que multiplicados dão N (a combinação contendo somente o N é uma das linhas a serem impressas).

Aluno: Matheus Almeida Silva - 316326
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void imprime_comb(int n, int vetor[], int qtd) {
    int i;
    if (n == 0) {
        printf ("%d", vetor[0]);
        for (i = 1; i < qtd; i++) {
            printf(" * %d", vetor[i]);
        }
        printf("\n");
    } else {
        i = 1;
        if (qtd > 0)
            i = vetor [qtd - 1]
        for (i = 1; i <= n; i++) {
            vetor [qtd] = i;
            imprime_comb(n - 1, vetor, qtd + 1);
        }
    }

}

int main() {
    int vetor[MAX];
    int n;
    printf("Insira o numero: ");
    scanf("%d", &n);
    if(n <= 1) {
        printf("Numero Invalido!!");
    } else {
        imprime_comb(n, vetor, 0);
    }

    return 0;
} 