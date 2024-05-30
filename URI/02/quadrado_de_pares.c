#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int N;
    int numero = 1;
    scanf("%d", &N);
    switch (N){
    case 6 ... 1999:
        do{
            int resto = numero % 2;
            int quadrado = numero * numero;
            if (resto == 0){
                printf("%d^2 = %d\n", numero, quadrado);
            }
            numero++;
        } while (numero <= N);

    }
return 0;

}
