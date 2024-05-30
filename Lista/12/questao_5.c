/*
5.Faça uma função recursiva que recebe um vetor de inteiros e retorna a quantidade de números pares que o vetor contém.

Aluno: Matheus Almeida Silva - 316326
*/

#include <stdio.h>
#include <stdlib.h>

void recebe_vetor(int* vetor, int n){           // Funcao que le e recebe os elementos de um vetor
    printf("Insira os elementos do vetor: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", vetor + i);
    }
}

int busca_par(int* vetor, int pos){          //Funcao recursiva que retorna a quantidade de pares do vetor
    if (pos < 0){
        return 0;
    }                
    else {
        if (vetor[pos] == 0 || vetor[pos] % 2 == 1)
            return busca_par(vetor, pos - 1);
        else
            return busca_par(vetor, pos - 1) + 1;
    }

}

int main (){                //Define o vetor e seu numero de elementos n, recebendo seus valores e imprimindo o numero de pares
    int n;
    printf("Insira o numero de elementos do vetor: ");
    scanf("%d", &n);

    int vetor[n];

    recebe_vetor(vetor, n);
    printf("O numero de pares eh: %d", busca_par(vetor, n - 1));

    return 0;
}