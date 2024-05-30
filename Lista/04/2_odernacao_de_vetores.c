/*2. (3 pontos) Ordenação de vetor. leia um inteiro positivo N representando a quantidade de
elementos de um vetor de reais V. Logo, leia os N elementos de V. Implemente um algoritmo que
ordena V baseado na seguinte ideia: selecionar o menor elemento do vetor e se não estiver na
primeira posição então trocar ele com a da primeira posição, repetir o processo para o sub-vetor
que começa na segunda posição e assim por diante até o sub-vetor que começa na última posição.
*/
#include <stdio.h>

int main(){
    int N;
    int i, j, x;                        // Define as variáveis i e j como contadores e a variável x para armazenamento do maior valor posterior
    scanf("%d", &N);
    int V[N];

    for (i = 0; i < N ; i++) {          // Lê o número inteiro N representando a quantidade de elementos do vetor V
        scanf("%d", &V[i]);
    }

    for (i = 1; i < N ; i++) {          // Realiza a repetição percorrendo todos os elementos dos vetores, com exceção do primeiro
         for (j = 0; j < i; j++) {      // Realiza uma repetição para verificar todos os elementos percorridos, isto é, a esquerda do último valor percorrido
            if (V[i] < V[j]) {          // Caso o elemento do vetor percorrido seja menor que o verificado, efetua a troca armazenando o elemento em x e substituindo os valores.
                x = V[j];
                V[j] = V[i];
                V[i] = x;
            } 
         }
    }

    for (i = 0; i < N; i++) {           //Imprime os elementos do vetor ordenado
        printf("%d ", V[i]);
    }


    return 0;

}
