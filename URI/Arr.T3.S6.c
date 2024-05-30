/*Ingrid Moraes,01.03, gerando valor por funcoes rendomicas e adicionando numeros novos a cada laço*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define DEZ 10

int main()
{
    int i, r;
    int valores[DEZ];
    int val_max=100;
    int esclhd;
    srand(time(0));

    for (i=0; i < DEZ; i++)
    {
        r=(int)rand()/(double)RAND_MAX*(val_max+1);
        valores[i]=r;
        printf("%5d",valores[i]);
    }
    printf("\n\nDigite um numero de 0 a 100.");
    scanf("%d",&esclhd);

    for (i=0; i< DEZ-1; i++)
    {
        valores[i]= valores[i+1];
    }
    valores [DEZ-1]= esclhd;
    printf("\n\n");

    for (i=0; i< DEZ; i++)
    {
        printf("%5d",valores[i]);
    }
    printf("\n\n");

    for (i=0; i<DEZ; i++)
    {
        if (i % 2==0)
            valores[i]=i;

        printf("%5d",valores[i]);
    }
    printf("\n\n");


    return(0);
}
