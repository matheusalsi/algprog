#include <stdio.h>
#include <stdlib.h>
#define ALUNOS 3
int main() {
    FILE * arquivo; //declara o ponteiro ao arquivo
    float nota;
    int i;
    //verifica se foi possível criar ou recriar o arquivo para escrita
    if(!(arquivo = fopen("notas.bin", "wb")))
        printf("Erro ao criar arquivo");
    else { //conseguiu criar o arquivo
        printf("Indique as notas:\n");
        for(i = 0; i < ALUNOS; i++) {//lê as notas e escreve as notas
            scanf("%f", &nota);//lê a nota
            fwrite(&nota, sizeof(float), 1, arquivo);//escreve a nota
        }
    } return 0;
}