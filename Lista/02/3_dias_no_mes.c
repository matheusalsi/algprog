#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
 
    int mes,ano;
    printf("Insira o mes e o ano:\n");
    scanf("%d %d", &mes, &ano);

    if(mes >= 1 && mes <= 12){    // executa o código se o mês for um inteiro de 1 a 12

        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)  // Imprime os meses com 31 dias
            printf("31 dias!\n");

        if(mes == 2){             // Se o mês for fevereiro, verifica se é um ano bissexto e quantos dias terá.
           
            if(ano % 4 == 0 && ano % 100 != 0)          // Se o ano for divísel por 4 e não for divísivel por 100, será bissexto.
                printf("29 dias!\n");
        
            if(ano % 100 == 0 ){                        //Casos onde o ano é divisível por 100
                
                if(ano % 400 == 0)                      // Se o ano for divísivel por 100 e for divísivel por 400 será bissexto.
                    printf("29 dias!\n");
            
                if(ano % 400 != 0)                      // Se o ano for divísivel por 100 e não for divísivel por 400 não será bissexto.
                    printf("28 dias!\n");                  
            }

            if (ano % 4 != 0)                           // Se o ano não for divísel por 4 não será bissexto.
                printf("28 dias!\n"); 
        }
        
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11)   // Imprime os meses com 30 dias
            printf("30 dias!\n");
    }


    return 0;
}