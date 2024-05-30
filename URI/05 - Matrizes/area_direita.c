#include <stdio.h>
#include <stdlib.h>
#define LINHA 12
#define COLUNA 12

int main () {
    double matriz[LINHA][COLUNA];
    double media, soma = 0.0;
    int i,j,p=5;
    char O;
    scanf("%c",&O);

    for(i = 0; i < LINHA; i++){
        for (j = 0; j < COLUNA; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }

    for (j = 7; j < COLUNA; j++) {
        for (i = p; i < j; i++) {
            soma += matriz[i][j];
        }
        p--;    
    }

    switch (O) {
    case 'S':
        printf("%.1lf\n", soma);
        break;
        

    case 'M':
        media = soma/30;
        printf("%.1lf\n", media);
        break;

    default:
        break;
    }

    return 0;
}
