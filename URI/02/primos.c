#include <stdio.h>
int main() {
    int N;
    int contador = 1;
    scanf("%d", &N);
    if(N >= 1 && N <= 100){
        while (contador <= N){
            int x;
            scanf("%d", &x);
            if (x > 1 && x <= 10000000){
                int divisor = 2;
                while (divisor <= x){
                    int resto = x % divisor;
                    if (divisor < x && resto == 0){
                        printf("%d nao eh primo\n", x);
                        break;
                    }else if(divisor == x){
                        printf("%d eh primo\n", x);
                    }
                    divisor++;   
                }
            }
            contador++; 
        }      
    }
    
    return 0;
}