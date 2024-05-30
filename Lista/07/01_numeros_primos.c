/*1. (2 pontos) Números primos. Um número é primo se for maior que 1 e somente for divisível
por 1 e por ele mesmo. Faça uma função tipada que recebe um número inteiro como parâmetro
e retorna 1 se ele é um número primo e zero, caso ele não seja primo. Implemente um programa
que lê um inteiro N do teclado e usando a função anterior, imprime o N-ésimo número primo.*/

#include <stdio.h>
int verifica_primo (int);

int main(){
    int N;                              // Inteiro N, que será lido e indicará a posição do numero e o tamanho do vetor
    int i = 2, j = 0;                   // Defini 2 contadores, um i percorrendo os valores de um em um e outro j para, quando o valor i for verdade, armazenar no vetor
    printf("Entre o inteiro: ");
    scanf("%d", &N);
    int primos[N];
    while (j < N) {                     //Realiza o laço enquanto j for menor que N, ou seja, até j ocupador todo o vetor
        if (verifica_primo(i) == 1){    //Caso i seja verdadeiro, ocupa o valor j e incrementa o j
            primos[j] = i;
            j++;
        }
        i++;
    }

    printf("O numero primo na posicao %d eh: %d", N, primos[N-1]);

    return 0;
}

int verifica_primo (int numero){                //Função tipada que recebe um número inteiro como parâmetro e retorna 1 se for primo e do contrário 0
    int resto, k;
    if (numero > 1){
        for (k = 2; k <= numero; k++){
            resto = numero % k;
            if (k < numero && resto == 0){
                return 0;
                break;
            } else if (k == numero) {
                return 1;
            }
        }
    } else {
        return 0;
    }
}



