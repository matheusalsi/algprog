/*
3.Semelhante ao exercício anterior, mas considerando que o vetor está ordenado. Neste caso, o chamado recursivo da sua função deve garantir que serão 
analisados no máximo a metade dos elementos do vetor recebido como parâmetro (Busca binária).

Aluno: Matheus Almeida Silva - 316326
*/

#include <stdio.h>
#include <stdlib.h>

void recebe_vetor(int* vetor, int n){
    printf("Insira os elementos do vetor de forma ordenada: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", vetor + i);
    }
}

int busca_binaria(int* vetor, int ini, int fim, int x){          //Funcao recursiva que retorna a posicao de x no vetor por busca binaria
    int pos = (ini + fim)/2;                                    //Pos recebe a metade do vetor

    if (ini > fim)                                              //Caso a posicao final seja maior que a inicial, o elemento nao esta no vetor e retorna -1
        return -1;
    if (vetor[pos] == x)                                        //Caso o elemente seja o mesmo do vetor, retorna a posicao pos
        return pos;
    if (vetor[pos] < x) {                                       //Caso o vetor na pos seja menor que x, realiza a recursao incrementado um na pos e passando como variavel inicio
        return busca_binaria(vetor, pos + 1, fim, x);
    } else {  
        return busca_binaria(vetor, ini, pos - 1, x);          //Do contrario, realiza a recursao decrementando um na pos e passando como variavel fim
    }

}

int main (){
    int x, n;

    printf("Insira o numero de elementos do vetor: ");
    scanf("%d", &n);

    int vetor[n];

    recebe_vetor(vetor, n);
    printf("Insira o numero x buscado: ");
    scanf("%d", &x);
    printf("X esta na posicao(considere posicao inial = 0): %d", busca_binaria(vetor, 0, n, x));

    return 0;
}