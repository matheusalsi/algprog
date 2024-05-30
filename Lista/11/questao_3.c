/*
VERSÃO ARQUIVO DE TEXTO!

OBS!!!: 
O Programa possui alguns problemas de funcionalidade mas com o intuito de ser avaliado, será enviado de forma incompleta. A parte não funcional do código conterá
observações para facilitar a avaliação.


3.Faça um programa para manipulação de países numa olimpíada. O programa deve usar uma estrutura para representar um país:

-Nome: String com 20 caracteres

-Número de medalhas de ouro: Inteiro

-Número de medalhas de prata: Inteiro

-Número de medalhas de bronze: Inteiro

O programa deve apresentar continuamente um menu com as seguintes opções:

-Incluir dados de país: O programa pede para o usuário informar os dados do país e os armazena no arquivo binário olimpiada.bin. Se o país já estiver no arquivo os
dados dele devem ser atualizados.

-Exibir países: O programa deve ler o arquivo binário e apresentar na tela os países ordenados: aqueles com mais ouros devem estar primeiro, depois aqueles com mais
prata e finalmente ordenados pelos bronzes.

Matheus Almeida Silva - 316326
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct pais {    //Define a struct
    char nome[20];
    int ouro;
    int prata;
    int bronze;

} pais, *pPais;

void limpa(char * texto) {  // Função que limpa a tela e recebe um texto a ser exibido
    system("cls");
    printf("%s\n\n", texto);
}

void aguarda() {            //Função que define um operador e enquanto não receber 0(falso) realiza um loop para aguardar a exibição da tela
    int op;
    do {
        printf("\nPara voltar ao menu principal digite 0\n");
        scanf("%d", &op);
    }while(op);
}

void le(pPais pais){     //Função que recebe do usuario os dados da struct
    puts("Insira o nome do pais:");
    gets(pais->nome);
    puts("Insira o numero de medalhas de ouro:");
    scanf("%d", &pais->ouro);
    puts("Insira o numero de medalhas de prata:");
    scanf("%d", &pais->prata);
    puts("Insira o numero de medalhas de bronze:");
    scanf("%d", &pais->bronze);
}

void printa(pPais pais){         //Funcao que printa para o usuario os dados da struct
    printf("\n%s\n%d\n%d\n%d\n", pais->nome, pais->ouro, pais->prata, pais->bronze);

}

int inclui(char *nome_arquivo, pPais pais){  //Funcao que inclui uma nova struct e, caso nao haja, cria o arquivo
    FILE * arquivo;
    if(arquivo = fopen(nome_arquivo, "a")) {
        fprintf(arquivo,"%s\n%d\n%d\n%d\n", pais->nome, pais->ouro, pais->prata, pais->bronze);
        fclose(arquivo);
        return 1;
    } else
        return 0;
}

int exibe(char *nome_arquivo, pPais pais, int *n){   //Funcao que faz a leitura da struct e inclui o valor no vetor de structs
    FILE * arquivo;
    if(arquivo = fopen(nome_arquivo, "r")){
        while (!feof(arquivo)) {
            fscanf(arquivo, "%s %d %d %d", &(pais + *n)->nome, &(pais + *n)->ouro, &(pais + *n)->prata, &(pais + *n)->bronze);
            *n = *n + 1;
        }
        fclose(arquivo);
        return 1;
    } else
        return 0;
}

void ordena(pPais paises, int n){   // AVISO!!: A FUNCAO ORDENA ESTA INCOMPLETA, POR ALGUM MOTIVO SÓ ORDENA OS VALORES SO SAO EXIBIDOS CORRETAMENTE APOS RETORNAR AO MENU E EXECUTAR O COMANDO DE NOVO
    pais ord;
    for (int i = 1; i < n; i++) {   //Percorre todos os paises até o final do vetor
        for (int j = 1; j <= i; j++)    // Percorre todos os paises anteriores ao pais i e ordena os vetores
        {
            if(paises[i].ouro > paises[i-j].ouro){
                ord = paises[i-j];
                paises[i-j] = paises[i];
                paises[i] = ord;
            } else if(paises[i].prata > paises[i-j].prata){
                ord = paises[i-j];
                paises[i-j] = paises[i];
                paises[i] = ord;
            } else if(paises[i].bronze > paises[i-j].bronze){
                ord = paises[i-j];
                paises[i-j] = paises[i];
                paises[i] = ord;
            }
        } 
        
    }
}

int atualiza(char *nome_arquivo, pPais pais){        //AVISO!!: A FUNCAO ATUALIZA ESTA INCOMPLETA NAO CONSEGUE ALTERAR VALORES POR ALGUM MOTIVO, SOMENTE ADICIONA-LOS AO FINAL /*Funcao que le e atualiza o arquivo caso o nome seja encontrado*/
    FILE * arquivo;
    char nome_corrente[50];
    int achou = 0;
    if((arquivo = fopen(nome_arquivo, "r+"))) {
        while (!feof(arquivo) && !achou) {
            if(fscanf(arquivo,"%s", &nome_corrente) > 0) {
                if(strcmp(pais->nome, nome_corrente) == 0) {
                    fprintf(arquivo,"%s\n%d\n%d\n%d\n", pais->nome, pais->ouro, pais->prata, pais->bronze);
                    achou = 1;
                }
            }
        }
        fclose(arquivo);
        if(!achou >= 0){
            inclui(nome_arquivo, pais);
        }

        return 1;
    }
    return 0;
}

int main (){        //Define o menu e realiza as operacoes
    pais paises[MAX];
    int op, sair = 0, n = 0;
    do {
        limpa("Escolha uma opcao:\n 1- Incluir pais\n 2- Exibir paises\n 3- Atualizar paises\n 4- Sair\n");
        scanf("%d", &op);
        getchar();
        switch(op) {
            case 1:
                le(paises);
                if(inclui("paises.txt", paises)) {
                    limpa("Pais incluso!");
                } else {
                    limpa("Erro ao incluir");
                }
                aguarda();
                break;
            case 2:
                if(exibe("paises.txt", paises + n, &n)){
                    ordena(paises, n);
                    for (int k = 0; k < n - 1; k++) {
                        printa(paises + k);
                    }
                n = 0;
                }else {
                    limpa("Erro ao ler");
                }
                aguarda();
                break;
            case 3:
                le(paises + n);
                if(atualiza("paises.txt", paises)) {
                    limpa("Pais atualizado!");
                } else {
                    limpa("Erro ao atualizar");
                }
                aguarda();
                break;
            case 4:
                sair = 1;
                break;
            default:
                limpa("Opcao Invalida!!!\n");
                aguarda();
        }
    }while(!sair);

}
