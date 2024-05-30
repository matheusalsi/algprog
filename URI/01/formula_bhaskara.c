#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
 
    double a, b ,c;
    double delta;
    
    scanf("%lf %lf %lf", &a, &b, &c);
    delta = pow(b,2) - 4 * a * c;

    if(a != 0 && delta >= 0){
        double r1, r2;
        r1 = (-1 * b + sqrt(delta))/(2 * a);
        r2 = (-1 * b - sqrt(delta))/(2 * a);
        printf("R1 = %.5lf\n", r1);
        printf("R2 = %.5lf\n", r2);
    }
    else
        printf("Impossivel calcular\n");

        
    return 0;
}