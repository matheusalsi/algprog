/*
VERSÃO ARQUIVO DE TEXTO!
1. Faça um programa que crie um arquivo binário, com nome informado pelo usuário, que armazene inteiros. O programa deve ler o nome do arquivo e as informações de
um limite inferior (li) e um limite superior (ls), escrevendo no arquivo todos os inteiros entre li e ls. Faça um segundo programa, que lê o nome de um arquivo binário
informado pelo usuário e substitui cada número par no arquivo pela sua metade.

Matheus Almeida Silva - 316326
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int salva(char *nome_arquivo, int li, int ls){      //Funcao que recebe a string como nome do arquivo, os limites inferiores e superior e salva os inteiros entre eles

    FILE * arquivo;
    if(arquivo = fopen(nome_arquivo, "w")) {
        for (int i = li + 1; i < ls; i++) {
            fprintf(arquivo, "%d\n", i);
        }
        fclose(arquivo);
        return 1;
    } else
        return 0;
}


int main(){     //Declara a string que recebe o nome do arquivo, realiza sua leitura e passa a string como parametro
    char nome_arquivo[50];
    int li, ls;

    printf("Insira o nome do arquivo com .txt: ");
    gets(nome_arquivo);
    printf("Insira o limite inferior e superior: ");
    scanf("%d %d", &li, &ls);

    if(salva(nome_arquivo, li, ls))
        printf("Dados salvos!");
    else
        printf("Erro ao salvar!");

    return 0;
}



