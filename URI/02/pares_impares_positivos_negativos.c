#include <stdio.h>
 
int main() {
 
    int par = 0, impar = 0, positivo = 0, negativo = 0;
    int contador = 1;
    int numero;
    
    while (contador <= 5){
        scanf("%d", &numero);
        if (numero % 2 == 0){
            par++;
        }
        if (numero % 2 != 0){
            impar++;
        }
        if (numero > 0){
            positivo++;
        }
        if (numero < 0){
            negativo++;
        }

        contador++;
    }
    
    printf("%d valor(es) par(es)\n", par);
    printf("%d valor(es) impar(es)\n", impar);
    printf("%d valor(es) positivo(s)\n", positivo);
    printf("%d valor(es) negativo(s)\n", negativo);


    return 0;
}