/*2. (2 pontos) Números perfeitos. Um número é perfeito se for à soma de todos seus divisores
próprios (os divisores diferentes dele mesmo). Faça uma função tipada que recebe um número
inteiro como parâmetro e retorna 1 se ele é um número perfeito e zero, caso ele não seja perfeito.
Implemente um programa que lê um inteiro N do teclado e usando a função anterior, imprime o
N-ésimo número perfeito.*/

#include <stdio.h>
int verifica_perfeito (int);

int main(){
    int N;                              // Inteiro N, que será lido e indicará a posição do numero e o tamanho do vetor
    int i = 2, j = 0;                   // Defini 2 contadores, um i percorrendo os valores de um em um e outro j para, quando o valor i for verdade, armazenar no vetor
    printf("Entre o inteiro: ");
    scanf("%d", &N);
    int perfeitos[N];
    while (j < N) {                     //Realiza o laço enquanto j for menor que N, ou seja, até j ocupador todo o vetor
        if (verifica_perfeito(i) == 1){    //Caso i seja verdadeiro, ocupa o valor j e incrementa o j
            perfeitos[j] = i;
            j++;
        }
        i++;
    }

    printf("O numero perfeito na posicao %d eh: %d", N, perfeitos[N-1]);

    return 0;
}

int verifica_perfeito (int numero){                //Função tipada que recebe um número inteiro como parâmetro e retorna 1 se for perfeito e do contrário 0
    int resto, k, soma = 0;
    for (k = 1; k < numero; k++) {
        resto = numero % k;
        if (resto == 0) {
            soma += k;
        }
    }
    if (numero == soma) {
        return 1;
    } else {
        return 0;
    }
}



