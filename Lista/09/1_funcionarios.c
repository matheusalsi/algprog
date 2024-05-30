/*
1. (2 pontos) Funcionários. Faça um programa que manipula informações sobre funcionários:
- O programa deve usar uma estrutura que representa funcionários, incluindo código, nome e
salário.
- O programa deve usar uma função sem retorno que recebe como parâmetro o vetor de funcionários
e o número de funcionários e que faz a leitura dos dados de cada funcionário.
- O programa deve usar uma função que recebe como parâmetro um funcionário e exibe as suas
informações.
- Na função principal do programa leia informações de N (assuma define N 5) e depois exiba
as informações dos funcionários lidos. Use as funções desenvolvidas para tal tarefa.

Aluno: Matheus Almeida Silva - 316326
*/
#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct funcionario {                            //Struct que representa os funcionarios
    int codigo;
    char nome [31];
    float salario;
}func;

void le(func f[N], int numero);                         //Prototipo da função sem retorno que recebe como parâmetro o vetor de funcionários e o número de funcionários e que faz a leitura dos dados de cada funcionário.
void exibe(func f);                                     //Prototipo da função que recebe como parâmetro um funcionário e exibe as suas informações.

int main (){                                            //Função principal que cria um vetor do tipo da struct, chama a função que lê e realize um loop na função de exibição
    func vetor[N];
    le (vetor, N);
    printf("\n");
    for (int i = 0; i < N; i++) {
        exibe(vetor[i]);
    }
    return 0;
}

void le(func f[N], int numero) {                       //Função de leitura recebe como parametro o vetor e o numero de funcionarios, utiliza o numero como limitador do loop e realiza a leitura dos vetores
    for (int j = 0; j < numero ; j++) {
        printf("Entre o codigo: ");
        scanf("%d", &f[j].codigo);
        printf("Entre o nome: ");
        scanf("%s",f[j].nome);
        printf("Entre o salario: ");
        scanf("%f", &f[j].salario);
    }
}

void exibe(func f) {                                  //Função que recebe uma variavel do tipo func e realiza a exibição do conteudo da struct
    printf("Codigo: %d\n", f.codigo);
    printf("Nome: %s\n", f.nome);
    printf("Salario: %.2f\n\n", f.salario);
}



