/*
VERSÃO ARQUIVO DE TEXTO!

OBS!!!: 
O Programa possui alguns problemas de funcionalidade mas com o intuito de ser avaliado, será enviado de forma incompleta. A parte não funcional do código conterá
observações para facilitar a avaliação.

2. Faça um programa para manipulação de contatos. O programa deve usar uma estrutura para representar um contato. A estrutura deve incluir os seguintes campos:

-Nome: String com 50 caracteres

-Endereço: String com 100 caracteres

-Telefone: String com 11 caracteres

-Email: String com 70 caracteres

O programa deve apresentar continuamente um menu com as seguintes opções:

-Incluir contato: O programa pede para o usuário informar os dados de um contato e cria um contato novo, adicionando ao fim de um arquivo binário.

-Exibir contatos: O programa deve ler o arquivo binário de contatos e apresentar na tela todos os contatos já salvos em ordem alfabética.

-Atualizar contato: O programa deve pedir para o usuário informar os dados do contato a ser atualizado e depois procurar o contato pelo nome e atualizá-lo em caso de existir, caso o contato não exista, deve ser adicionado no final do arquivo.
Considere que o programa deve ser capaz de lidar com até 100 contatos. Mas teste com apenas 3.

Matheus Almeida Silva - 316326
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct contato {    //Define a struct
    char nome[50];
    char endereco[100];
    char telefone[11];
    char email[70];

} cont, *pCont;

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

void le(pCont contato){     //Função que recebe do usuario os dados da struct
    puts("Insira o nome:");
    gets(contato->nome);
    puts("Insira o endereco:");
    gets(contato->endereco);
    puts("Insira o telefone:");
    gets(contato->telefone);
    puts("Insira o email:");
    gets(contato->email);
}

void printa(pCont contato){         //Funcao que printa para o usuario os dados da struct
    printf("\n%s\n%s\n%s\n%s\n", contato->nome, contato->endereco, contato->telefone, contato->email);

}

int inclui(char *nome_arquivo, pCont contato){  //Funcao que inclui uma nova struct e, caso nao haja, cria o arquivo
    FILE * arquivo;
    if(arquivo = fopen(nome_arquivo, "a")) {
        fprintf(arquivo,"%s\n%s\n%s\n%s\n", contato->nome, contato->endereco, contato->telefone, contato->email);
        fclose(arquivo);
        return 1;
    } else
        return 0;
}

int exibe(char *nome_arquivo, pCont contato, int *n){   //Funcao que faz a leitura da struct e inclui o valor no vetor de structs
    FILE * arquivo;
    if(arquivo = fopen(nome_arquivo, "r")){
        while (!feof(arquivo)) {
            fscanf(arquivo, "%s %s %s %s", &(contato + *n)->nome, &(contato + *n)->endereco, &(contato + *n)->telefone, &(contato + *n)->email);
            *n = *n + 1;
        }
        fclose(arquivo);
        return 1;
    } else
        return 0;
}

int atualiza(char *nome_arquivo, pCont contato){        //AVISO!!: A FUNCAO ATUALIZA ESTA INCOMPLETA NAO CONSEGUE ALTERAR VALORES POR ALGUM MOTIVO, SOMENTE ADICIONA-LOS AO FINAL /*Funcao que le e atualiza o arquivo caso o nome seja encontrado*/
    FILE * arquivo;
    char nome_corrente[50];
    int achou = 0;
    if((arquivo = fopen(nome_arquivo, "r+"))) {
        while (!feof(arquivo) && !achou) {
            if(fscanf(arquivo,"%s", &nome_corrente) > 0) {
                if(strcmp(contato->nome, nome_corrente) == 0) {
                    fprintf(arquivo, "%s\n%s\n%s\n%s\n", contato->nome, contato->endereco, contato->telefone, contato->email);
                    achou = 1;
                }
            }
        }
        fclose(arquivo);
        if(!achou >= 0){
            inclui(nome_arquivo, contato);
        }

        return 1;
    }
    return 0;
}

int main (){            //Define o menu e realiza as operacoes
    cont contatos[MAX];
    int op, sair = 0, n = 0;
    do {
        limpa("Escolha uma opcao:\n 1- Incluir Contato\n 2- Exibir Contato\n 3- Atualizar contatos\n 4- Sair\n");
        scanf("%d", &op);
        getchar();
        switch(op) {
            case 1:
                le(contatos);
                if(inclui("contatos.txt", contatos)) {
                    limpa("Contato incluso!");
                } else {
                    limpa("Erro ao incluir");
                }
                aguarda();
                break;
            case 2:
                if(exibe("contatos.txt", contatos + n, &n)){
                    for (int j = 0; j < n - 1; j++) {
                        printa(contatos + j);
                    }
                n = 0;
                }else {
                    limpa("Erro ao ler");
                }
                aguarda();
                break;
            case 3:
                le(contatos + n);
                if(atualiza("contatos.txt", contatos)) {
                    limpa("Contato atualizado!");
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
