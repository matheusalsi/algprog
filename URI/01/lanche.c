#include <stdio.h>
#include <stdlib.h>

int main() {
 
    int a, b;
    float valor;

    scanf("%d %d", &a, &b);
    
    if(a == 1)
        valor = 4 * b;
    if(a == 2)
        valor = 4.5 * b;
    if(a == 3)
        valor = 5 * b;
    if(a == 4)
        valor = 2 * b;
    if(a == 5)
        valor = 1.5 * b;

    printf("Total: R$ %.2f\n", valor);

    return 0;
}