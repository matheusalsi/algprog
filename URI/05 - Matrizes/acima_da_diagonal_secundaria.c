#include <stdio.h>
#include <stdlib.h>
#define LINHA 12
#define COLUNA 12

int main () {
    double matriz[LINHA][COLUNA];
    double media, soma = 0.0;
    int i,j;
    char O;
    scanf("%c",&O);

    for(i = 0; i < LINHA; i++){
        for (j = 0; j < LINHA; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }
    for (j = 0; j < COLUNA - 1; j++) {
        for (i = 0; i < 11 - j ; i++) {
            soma += matriz[i][j];
        }
    }
    
    switch (O) {
    case 'S':
        printf("%.1lf\n", soma);
        break;
        

    case 'M':
        media = soma/66;
        printf("%.1lf\n", media);
        break;

    default:
        break;
    }

    return 0;
}
