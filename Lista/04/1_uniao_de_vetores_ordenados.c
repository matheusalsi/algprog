/*1. (3 ponto) União de vetores ordenados. leia dois inteiros positivos N1 e N2, representando
cada um, respectivamente, a quantidade de elementos de um vetor de reais V1 e outro V2. Logo,
leia os N1 elementos de V1 e os N2 elementos de V2. Assumindo que os elementos de V1 estejam
ordenados e que os de V2 também estejam ordenados, defina um novo vetor V3, com todos os
elementos ordenados, que resulta da união de V1 e de V2. Imprima, de forma ordenada, os
elementos de V3.*/

#include <stdio.h>

int main(){
    int N1, N2;
    int i;
    scanf("%d %d", &N1, &N2);
    int V1[N1], V2[N2], V3[N1 + N2];
    
    for (i = 0; i < N1 ; i++) {
        scanf("%d", &V1[i]);
    }

    for (i = 0; i < N2 ; i++) {
        scanf("%d", &V2[i]);
    }

    for (i = 0; i < N1 + N2; i++) {
        if (V1[i] < V2[i]) {
            V3[] = V1[i];
            V3[] = V2[i];

        } else {
            V3[] = V2[i];
            V3[n] = V1[i];
        }
    }

    for (i = 0; i < N1 +N2; i++) {
        printf("%d ", V3[i]);
    }

    return 0;

}