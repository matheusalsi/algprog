#include <stdio.h>

int main(){
    int N[10];
    int i;
    scanf("%d", &N[0]);

    if (N[0] <= 50 ) {
        for ( i = 1; i <= 9; i++) {
            N[i] = N[i-1]*2 ;
        }

        for ( i = 0; i <= 9; i++) {
            printf("N[%d] = %d\n", i, N[i]);
        }
    }


return 0;

}
