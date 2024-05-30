#include<stdio.h>

int main() {

    int x;
    int numero = 1;
    scanf("%d", &x);
    
    if (x >= 1 && x <= 1000){
        do
        {
            int resto = numero % 2;
            if (resto != 0){
                printf("%d\n", numero);
            }

            numero++;

        }while(numero <= x);
    }
  
    return 0;
}