#include <stdio.h>
int menor_valor(int *vetor, int N);
int local(int *vetor, int N);

int main() {
    int N , i, valor, posicao;
    scanf("%d", &N);
    int vetor[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }
    valor = menor_valor(vetor, N);
    posicao = local(vetor, N);
    printf("Menor valor: %d\n", valor);
    printf("Posicao: %d\n", posicao);

    return 0;
}



int menor_valor(int *vetor, int N) {
    int i, p;
    int ponteiro*;
    for (i = 0; i < N; i++) {
        if (i == 0) {
            p = vetor[i];
        }

        if (vetor[i] <= p) {
            p = vetor[i];
        }
    }
    return p;
}

int local(int *vetor, int N){
    int i, p, q;
    for (i = 0; i < N; i++) {
        if (i == 0) {
            p = vetor[i];
            q = i;
        }

        if (vetor[i] <= p) {
            p = vetor[i];
            q = i;
        }
    }
    return q;
}


