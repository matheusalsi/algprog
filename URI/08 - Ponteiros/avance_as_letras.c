#include <stdio.h>

int verifica_numero(char *c, int p);

int main(){
    int p, valor;
    char c[51];

    while(scanf("%s",&c) != EOF){
        scanf("%d",&p);
        valor = verifica_numero(c, p);
        printf("%d\n",valor);

    }
    return 0;
}

int verifica_numero(char *c, int p) {
    int i, processo = 0, rastro = 0;

    for(i = 0; *(c + i) != '\0'; i++){
        if(*(c + i) == 'W'){
            rastro++;
            if(processo > 0){
                processo = 0;
                rastro++;
            }
        }else{
            processo++;
            if(processo == p){
                rastro++;
                processo = 0;
            }
        }
    }
    if(processo > 0){
        rastro ++;
    }

    return rastro;
}