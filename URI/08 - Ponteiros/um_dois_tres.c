#include <stdio.h>
#include <string.h>

int verifica_numero(char *nome);


int main(){
    int N, valor;
    char nome[5];
    scanf("%d",&N);
    while(N--){
        scanf("%s", &nome);
        valor = verifica_numero(nome);
        printf("%d\n", valor);
    }
    return 0;
}

int verifica_numero(char *nome) {
    int numero=0, j;
    char n0, n1, n2;
    if (strlen(nome) == 5){
            numero = 3;
        } else {
            for (j = 0; j < 6; j++) {
                if (nome[j] == '\0'){
                    break;
                }
                n0 = nome[0];
                n1 = nome[1];
                n2 = nome[2];
                if ((n0 == 'o' && n1 == 'n') || (n0 == 'o' && n2 == 'e') || (n1 == 'n' && n2 == 'e')){
                    numero = 1;
                } else{
                    numero = 2;
                }
            }
        }
    return numero;
}

