/*
4. Implemente um algoritmo para ordenar um vetor de inteiros seguindo a ideia do Quicksort visto e discutido em sala de aula.

Aluno: Matheus Almeida Silva - 316326
*/
#include <stdio.h>
#include <stdlib.h>

#define swap( _a, _b ) do{ int _tmp = _a; _a = _b; _b = _tmp; } while(0)            //Operador de trocar a ser utilizado no quicksort
#define N 5

void exibe(int* vetor, int n){     // Funcao que exibe os elementos de um vetor
    printf("O vetor ordenado eh:");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
}


void ordena_quicksort(int* vetor, int begin, int end){          //Funcao recursiva que usando a ideia do quicksort, ordena os elementos do vetor
    if(begin < end){                                            //Condicao de parada, ocorre quando a variavel end, do ultimo elemento, é maior que a de inicio
        int i = begin + 1;                                      //Define 3 variaveis para servir de comparacao dos elementos
        int j = end;
        int k = vetor[begin];

        while( i < j ) {                                        //Loop principal para executa enquanto a posicao inicial for menor que a final, fazendo a varredura de ambos os lados do elemento de referencia k
            if(vetor[i] <= k) {                                 //Caso o elemento na posicao i seja menor ou igual que o elemento k, incrementa 1 no i(elemento de referencia)
                i++;
            }
            else if(vetor[j] >= k) {                            //Caso o elemento na posicao j for maior ou igual que k, decrementa em um
                j--;
            } else {
                swap(vetor[i], vetor[j]);                       //Do Contrario, troca os elementos de i pelo de k
            }
        }

        if( vetor[i] < k ) {                                    //Caso o elemento na posicao i seja menor que o k, realiza a troca de i pelo k
            swap(vetor[i], vetor[begin]);
            i--;
        } else {                                                //Do Contrario realiza a troca com o elemento i - 1
            i--;
            swap(vetor[i], vetor[begin]);                     
        }
        ordena_quicksort(vetor, begin, i);                      //Recursao da funcao 
        ordena_quicksort(vetor, j, end);
    }
}

int main (){                //Define o vetor e seus elementos e chama as funcoes para ordenar e exibir o vetor ordenado
    int vetor[N] = {-7, 6, -3, 0, 4};

    ordena_quicksort(vetor, 0, N);
    exibe(vetor, N);

    return 0;
}
