#include <stdio.h>

int main() {
    int N, i, j,k,resto, elemento, limitador, p, q,a,b;

    while (1) {
        scanf("%d", &N);
        if (N == 0) {
            break;
        }

        int matriz[N][N];
        limitador = N;
        a=0, b=0, elemento=1;

        if(N%2==0){
            resto=N/2;
        } else if(N%2==1){
             resto=(N/2)+1;
         }

        for(k=1; k<=resto; k++) {
            for(i = a; i<limitador; i++) {
                for(j = b; j<limitador; j++)
                    matriz[i][j]=elemento;
            }
            elemento++;
            limitador--;
            a++;
            b++;
            }


        for(i=0; i<N; i++) {
            for(j=0; j<N; j++) {
                if(j==0){
                    printf("%3d",matriz[i][j]);
                } else {
                    printf(" %3d",matriz[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
