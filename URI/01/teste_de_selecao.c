#include <stdio.h>
#include <stdlib.h>

int main() {
 
    int a, b, c, d;
    int somacd, somaab, restoa;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    somacd = c + d;
    somaab = a + b;
    restoa = a % 2;

    if (b > c && d > a && somacd > somaab && c > 0 && d > 0 && restoa==0)
        printf("Valores aceitos\n");
    else
        printf("Valores nao aceitos\n");
    
    return 0;
}