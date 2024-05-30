#include <stdio.h>

int main(){
    int M,N;
    int contador;
    while (1){
        scanf("%d %d", &M,&N);
        if (M <= 0 || N <= 0){
            break;
        }
        if (M > N){
            int soma = 0;
            contador = N;
            while (contador <= M){
                soma += contador;
                printf("%d ", contador);
                contador++;
            }
            printf("Sum=%d\n", soma);
        }

        if (M < N ){
            int soma = 0;
            contador = M;
            while (contador <= N){
                soma += contador;
                printf("%d ", contador);
                contador++;
            }
            printf("Sum=%d\n", soma);
        }

        if (M == N){
            int soma = M + N;
            printf("%d %d Sum=%d\n", M, N, soma);
        }
    }
    return 0;

}
