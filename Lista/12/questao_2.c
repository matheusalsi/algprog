/*
2. Escreva uma função recursiva que recebe um vetor de números inteiros (em qualquer ordem) e um inteiro X. Se X está no vetor, sua função deve retorna a posição 
em que X aparece, caso contrário a sua função deve retornar -1.


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

int busca_vetor(int* vetor, int pos, int x){          //Funcao recursiva que retorna a posicao de x no vetor
    if (pos == 0){                                      //Condicao de parada, caso a pos seja 0(inicial) 
        if(vetor[pos] == x)                             //Caso o elemento na posicao inicial seja x, retorna a pos. Do contrário retorna -1.
            return pos;
        else
            return -1; 
    }                                  
    else {
        if(vetor[pos] == x)                             //Se o elemento na pos for x, retorna a pos
            return pos;
        else
            return busca_vetor(vetor, pos - 1, x);      //Do Contrario realiza a recursao com a posicao anterior
    }

}

int main (){                //Define o vetor e as variaveis x e n, respectivamente o numero buscado e o numero de elementos do vetor
    int x, n;

    printf("Insira o numero de elementos do vetor: ");
    scanf("%d", &n);

    int vetor[n];
    
    recebe_vetor(vetor, n);
    printf("Insira o numero x buscado: ");
    scanf("%d", &x);
    printf("X esta na posicao(considere posicao inicial = 0): %d", busca_vetor(vetor, n, x));

    return 0;
}