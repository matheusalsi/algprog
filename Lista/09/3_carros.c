/*
3. (2 pontos) Carros Faça um programa que armazena dados de 10 carros:
- Cada carro possui comprimento, largura, consumo médio, capacidade de passageiros e preço.
- O programa deve ler os dados dos 10 carros e armazenar em um vetor de carros.
- O programa deve informar as informações de todos os carros que possuem o menor preço (se
mais de um carro tiver o mesmo preço mais baixo, todos devem ser exibidos).
- O programa deve usar uma estrutura para representar os carros, e armazená-los em um vetor.

Aluno: Matheus Almeida Silva - 316326
*/
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#define n 10

typedef struct carro {                                          // Struct com as váriaveis a serem fornecidas
    float comprimento;
    float largura;
    float consumo;
    int capacidade;
    float preco;
}car, *ptrcar;


void le(ptrcar c);                                              //Prototipo da Função para a leitura do vetor, recebe um ponteiro da struct, pede os valores e os armazena na struct do vetor
void exibe(car c);                                              //Prototipo da Função que recebe um struct e imprime eles 
void compara_exibe(car valor[n]);                               //Prototipo da função que compara e exibe as informações do(s) carro(s) de menor preço

int main (){
    car dados[n];
    for (int i = 0; i < n; i++){                                //Função principal que cria o vetor de struct, executa um loop chamando a função de leitura e chama a função compara
        le(dados + i);
    }
    compara_exibe(dados);
    return 0;
}

void le(ptrcar c) {
    printf("Informe o comprimento: ");
    scanf("%f", &c->comprimento);
    printf("Informe a largura: ");
    scanf("%f", &c->largura);
    printf("Informe o consumo medio: ");
    scanf("%f", &c->consumo);
    printf("Informe a capacidade de passageiros: ");
    scanf("%d", &c->capacidade);
    printf("Informe o preco: ");
    scanf("%f", &c->preco);
}


void exibe(car c) {
    printf("Comprimento: %.2f\n", c.comprimento);
    printf("Largura: %.2f\n", c.largura);
    printf("Consumo medio: %.2f\n", c.consumo);
    printf("Capacidade de passageiros: %d\n", c.capacidade);
    printf("Preco: %.2f\n\n", c.preco);
}

void compara_exibe(car valor[n]) {
    car maior[n];
    int k = 1;
    maior[0] = valor[0];

    for (int i = 1; i < n; i++) {
        if (valor[i].preco > maior[0].preco) {
            maior[0] = valor[i];
            k = 1;
        } else if (maior[0].preco == valor[i].preco){
            maior[0+k] = valor[i];
            k++;
        } 
    }  
    
    for (int j = 0; j < k; j++) {
        exibe(maior[j]);
    }
}
