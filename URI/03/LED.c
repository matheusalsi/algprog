#include <stdio.h>
#include <string.h>

int main(){
    char V[102];
    int N;
    int i, j, leds;
    

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        leds = 0;
        scanf("%s", V);
        for (j = 0; j < strlen(V); j++) {
            switch (V[j]) {
            case '1': leds += 2; break;
            case '2': leds += 5; break;
            case '3': leds += 5; break;
            case '4': leds += 4; break;
            case '5': leds += 5; break;
            case '6': leds += 6; break;
            case '7': leds += 3; break;
            case '8': leds += 7; break;
            case '9': leds += 6; break;
            case '0': leds += 6; break;
            default: break;
            }
        }
            printf("%d leds\n", leds);
            leds = 0;
        }


    return 0;

}
