#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
#define TAM2 11
#define AUX 30

int main ()
{
    char texto[TAM];
    char mat [TAM2][AUX];
    int i, j, k, tamanho;
    int numb_plv, contador;
    puts ("Digite o texto que desejar:");
    gets (texto);

    tamanho= strlen(texto);
    numb_plv = 1;
    j = 0;
    k = 0;
    if (tamanho < TAM)
    {
        printf("O texto digitado tem o tamanho menor que %d.\n", TAM);

        for (i=0; i < strlen(texto); i++)
        {
            if (texto[i] != ' ')
            {
                mat[j][k] = texto[i];
                k++;
            } else {
                j++;
                k = 0;
                numb_plv++;
            }         
        }

        for (i = 0; i < numb_plv; i++)
        {
        printf("%s\n", mat[i]);    
        }

    } else
        if (tamanho == TAM)
        printf ("\nO texto tem o tamanho de %d.",TAM);


    return (0);
}
