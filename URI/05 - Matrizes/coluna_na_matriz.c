#include <stdio.h>
#include <stdlib.h>
#define LINHA 12
#define COLUNA 12

int main () {
    float matriz[LINHA][COLUNA];
    float media, soma = 0.0;
    int C,i,j;
    char T;
    scanf("%d %c", &C, &T);

    for(i = 0; i < LINHA; i++){
        for (j = 0; j < LINHA; j++){
            scanf("%f", &matriz[i][j]);
        }
    }

    switch (T) {
    case 'S':
        for (i = 0; i < LINHA; i++) {
            soma += matriz[i][C];
        }
        printf("%.1f\n", soma);
        break;

    case 'M':
        for (i = 0; i < LINHA; i++) {
            soma += matriz[i][C];
        }
        media = soma/LINHA;
        printf("%.1f\n", media);
        break;

    default:
        break;
    }

    return 0;
}
