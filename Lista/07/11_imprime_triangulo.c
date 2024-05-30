/*9. (4 pontos) Imprime triângulo. Faça uma função sem retorno que lê um número inteiro que
representa o tamanho da base de um triângulo e desenhe um triângulo invertido na tela, usando
caracteres ’*’. Implemente um programa que pergunta ao usuário se deseja sair e, enquanto o
usuário responda não, leia um número inteiro e imprima o triângulo associado a ele.*/
#include <stdio.h>
#include <string.h>

void imprime_triangulo(int);                // Protótipo da Função do triangulo invertido


int main(){
    char resposta[4];                       //Define uma string para receber a resposta do usuário
    int N, v;                               //Define o Inteiro N que será a base do triangulo e um inteiro v para verificar a resposta
    do {
        printf("Deseja sair? ");
        scanf("%s", resposta);
        if (resposta[0] == 'N' && resposta[1] == 'a' && resposta[2] == 'o') {       //Caso os caracteres das respostas satisfaçam a a resposta "Nao", o valor v assume 1.
            v = 1;
        } else {        // Caso a resposta seja diferente de "Nao", v recebe 0 e para o programa.
            v = 0;
            break;
        }
        printf("Entre o numero: ");         //Executa a pergunta, recebe o inteiro N e realiza a função imprime_triangulo para a base N
        scanf("%d", &N);
        imprime_triangulo(N);
        resposta[0] = '\0';                 //Limpa a string resposta

    } while (v == 1);           //Executa a repetição enquanto v == 1, ou seja, enquanto a resposta for "Nao"

    return 0;
}




void imprime_triangulo(int base){       //Função sem retorno que recebe como parâmetro o inteiro N, sendo a base do triângulo.
    int j,k = 0,n;                      //Define os inteiros tal que j será o contador de "*", k um valor de referência para n por linha pulada e n o espaço dado para cada linha
    while(base > 0) {
        if (k > 0) {
            for (n = 0; n < k; n++) {
                printf(" ");
            }
        }
        for (j = 1; j <= base; j++) {
                printf("*");
        }
        if(base == 2) {                 //Realiza a diminuição da base por linha 
            base--;                     //Caso a base seja 2, subtrai 1 da base seguinte
        }else if(base != 2) {
            base -= 2;                  //Caso a base seja diferente de 2, subtrai 2 da base seguinte
        }

        printf("\n");
        k++;                            //Incrementa o j de refência para o " " executado no n
    }
    
}