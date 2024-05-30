#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
 
    int dia;
    printf("Entre o dia:\n");
    scanf("%d", &dia);

    if(dia >= 1 && dia <= 7){
        if(dia > 1 && dia < 7)
            printf("Dia util!");

        if(dia == 1 || dia == 7 )
            printf("Fim de semana!");
    }    

    if(dia < 1 || dia > 7)
        printf("Invalido!");


    return 0;
}