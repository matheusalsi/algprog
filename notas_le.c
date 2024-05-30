#include <stdio.h>
#include <stdlib.h>
#define ALUNOS 8
int main() {
    FILE * arquivo; //declara o ponteiro ao arquivo
    float notas[ALUNOS];
    int i;
    //verifica se foi possível criar ou recriar o arquivo para escrita
    if(!(arquivo = fopen("teste2.bin", "rb")))
        printf("Erro ao criar arquivo");
    else { //conseguiu criar o arquivo
        fread(notas, sizeof(float),ALUNOS,arquivo);
        for(i = 0; i < ALUNOS; i++) {//lê as notas e escreve as notas
            printf("Nota %d: %f\n",i+1,notas[i]);//escreve a nota
        }
    } return 0;
}
