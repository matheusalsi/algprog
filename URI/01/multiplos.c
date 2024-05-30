#include <stdio.h>
#include <stdlib.h>

int main() {
 
    int a, b;
    int resto;
    scanf("%d %d", &a, &b);
    if (a > b)
        resto = a % b;
    if (a < b)
        resto = b % a;
    if (resto == 0)
        printf("Sao Multiplos\n");
    if (resto != 0)
        printf("Nao sao Multiplos\n");
    return 0;
}