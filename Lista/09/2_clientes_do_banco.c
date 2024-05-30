/*
2. (2 pontos) Clientes do banco. Faça um programa que armazena dados de 10 clientes de um
banco:
- O programa deve usar uma estrutura para representar os clientes, e armazená-los em um vetor.
- Cada cliente possui um código (número inteiro), e um saldo.
- O programa deve ler o código e o saldo de cada cliente.
- O programa deve determinar qual é o maior saldo bancário entre os clientes e informar os
dados dos clientes que possuem tal saldo (se mais de um cliente possuir tal saldo, todos devem
ser informados).

Aluno: Matheus Almeida Silva - 316326
*/
#include <stdio.h>
#include <stdlib.h>
#define n 10

typedef struct cliente {                     // Struct com as váriaveis a serem fornecidas
    int codigo;
    float saldo;
}clie, *ptrclie;


void le(ptrclie c);                         //Prototipo da Função para a leitura do vetor, recebe um ponteiro da struct, pede os valores e os armazena na struct do vetor
void exibe(clie c);                         //Prototipo da Função que recebe um struct e imprime eles 
void compara_exibe(clie valor[n]);          //Prototipo da função que compara e exibe as informações do(s) cliente(s) com maior saldo

int main (){                                //Função principal que cria o vetor de struct, executa um loop chamando a função de leitura e chama a função compara
    clie dados[n];
    for (int i = 0; i < n; i++){
        le(dados + i);
    }
    compara_exibe(dados);
    return 0;
}

void le(ptrclie c) {
    printf("Informe o codigo: ");
    scanf("%d", &c->codigo);
    printf("Informe o saldo: ");
    scanf("%f", &c->saldo);
}


void exibe(clie c) {
    printf("Codigo: %d\n", c.codigo);
    printf("Salario: %.2f\n\n", c.saldo);
}

void compara_exibe(clie valor[n]) {
    clie maior[n];
    int k = 1;
    maior[0] = valor[0];

    for (int i = 1; i < n; i++) {
        if (valor[i].saldo > maior[0].saldo) {
            maior[0] = valor[i];
            k = 1;
        } else if (maior[0].saldo == valor[i].saldo){
            maior[0+k] = valor[i];
            k++;
        } 
    }  
    for (int j = 0; j < k; j++) {
        exibe(maior[j]);
    }
}

