#include <stdio.h>

int main(){

    int I;
    int contador = 1;
    scanf("%d", &I);

    switch (I){
        case 2 ... 10000:
            printf("Feliz nat");
            while (contador <= I){
                printf("a");
                contador++;
            }
            printf("l!\n");
            break;
        default:
            break;
    }
return 0;

}
