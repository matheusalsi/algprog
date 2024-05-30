/*
VERSÃO ARQUIVO DE TEXTO!

OBS!!!: 
O Programa possui alguns problemas de funcionalidade mas com o intuito de ser avaliado, será enviado de forma incompleta. A parte não funcional do código conterá
observações para facilitar a avaliação.

1. Faça um programa que crie um arquivo binário, com nome informado pelo usuário, que armazene inteiros. O programa deve ler o nome do arquivo e as informações de
um limite inferior (li) e um limite superior (ls), escrevendo no arquivo todos os inteiros entre li e ls. Faça um segundo programa, que lê o nome de um arquivo binário
informado pelo usuário e substitui cada número par no arquivo pela sua metade.

Matheus Almeida Silva - 316326
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int valor(char *valor_corrente){        //Funcao responsavel por transformar a string do valor em um inteiro e retorna-lo
    int valor;
    valor = atoi(valor_corrente);
    return valor;
}

int divide_valor(int valor){        //Funcao responsavel por retornar metade do valor de um inteiro
    int metade;
    metade = valor/2;
    return metade;
}

int atualiza(char *nome_arquivo){   //AVISO!!: A FUNCAO ATUALIZA ESTA INCOMPLETA NAO CONSEGUE ALTERAR VALORES POR ALGUM MOTIVO, SOMENTE ADICIONA-LOS /*Funcao que realiza a leitura do arquivo e caso seja par, subistitui por sua metade*/
    FILE * arquivo;
    char valor_corrente[10];
    if(arquivo = fopen(nome_arquivo, "r+")) {
        while (!feof(arquivo)) {
            if(fscanf(arquivo,"%s", &valor_corrente) > 0){
                if(valor(valor_corrente) % 2 == 0){
                    printf("%d %d\n", valor(valor_corrente), divide_valor(valor(valor_corrente)));
                    fprintf(arquivo, "%d\n", divide_valor(valor(valor_corrente)));
                }
            }
        }
        fclose(arquivo);
        return 1;
    }
    return 0;
}


int main(){             //Declara a string que recebe o nome do arquivo, realiza sua leitura e passa a string como parametro 
    char nome_arquivo[50];      
    printf("Insira o nome do arquivo: ");
    gets(nome_arquivo);

    if(atualiza(nome_arquivo))
        printf("Leitura e substituicao completa!");
    else
        printf("Erro ao ler!");

    return 0;
}

