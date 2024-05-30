/*11. (4 pontos) Persistência multiplicativa. A persistência multiplicativa de um número inteiro
é o número de vezes que os dígitos deste número devem ser multiplicados, para que o resultado
chegue a um único dígito. Faça uma função tipada que recebe um número inteiro como parâmetro
e retorna a sua persistência multiplicativa. Implemente um programa que pergunta ao usuário se
deseja sair e, enquanto o usuário responda não, leia um número inteiro e imprima sua persistência
multiplicativa.*/

#include <stdio.h>
#include <string.h>

int inverte (int);

int main(){
    char resposta[4];
    int N, x;
    do {
        printf("Deseja sair? ");
        gets(resposta);
        if (strcmp(resposta,"Nao") == 0) {
            printf("Entre o numero: ");
            scanf("%d", &N);
            x = inverte(N);
            printf("O Numero invetido eh: %d", x);
        }
    } while (strcmp(resposta,"Sim") != 0);
    
    return 0;
}



int inverte (int numero){
    int i;
    
    

}