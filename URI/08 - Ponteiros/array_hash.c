#include <stdio.h>
int* calcula_hash(char *string, int j);

int main(){
    int N, L, i, j, k;
    char string[51];
    int hash, copia;

    scanf("%d",&N);
    for(i = 0; i < N; i++){
        scanf("%d",&L);
        hash = 0;

        for(j = 0; j < L; j++){
            scanf("%s",&string);
            copia = *calcula_hash(string, j);
            hash += copia;
        }
        printf("%d\n", hash);
    }
    return 0;
}

int* calcula_hash(char *string, int j){
    int k, soma = 0;
    int *ponteiro;
    for(k = 0; string[k] != '\0'; k++){
        soma += string[k] - 65 + j + k;
    }
    ponteiro = &soma;
    return ponteiro;
}

