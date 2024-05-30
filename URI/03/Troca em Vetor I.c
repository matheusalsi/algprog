#include <stdio.h>

int main(){
    int N[20];
    int i;

    for (i = 19; i >= 0; i--) {
        scanf("%d", &N[i]);
    }
    
    for (i = 0; i <= 19; i++) {
        printf("N[%d] = %d\n", i, N[i]);
    }
    

return 0;

}
