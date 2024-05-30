#include<stdio.h>
int main () {
    int variavel, * ponteiro, copia;
    
    ponteiro = &variavel;//recebe o ENDEREÇO de variável
    variavel = 100;

    copia = *ponteiro;//recebe o VALOR que apontado por ponteiro
    printf("Variavel: %d\nCopia: %d\n", variavel, copia) ;

    //O %p indica que o valor impresso é um endereço de memória (ponteiro)
    printf("Conteudo apontado: %d\nPonteiro: %p\n", *ponteiro, ponteiro) ;
    return 0;
}
