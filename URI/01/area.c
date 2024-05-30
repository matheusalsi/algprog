#include <stdio.h>
#include <stdlib.h>

int main() {
 
    float base, altura;
    float area;
    printf("Entre a base: ");
    scanf("%f", &base);
    printf("Entre a altura: ");
    scanf("%f", &altura);
    area = base * altura;
    printf("Area: %f \n", area);
    return 0;
}