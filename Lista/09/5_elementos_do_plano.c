/*
5. (2 pontos) Elementos do plano. Faça um trabalho que trabalhe com elementos no plano:
- O programa deve possuir uma definição (estrutura) para pontos no plano, assim como funções
para ler e imprimir um ponto.
- Usando a definição de ponto, o programa deve permitir definir (estrutura) segmentos de retas,
assim como funções para leitura, escrita e cálculo de comprimento de um segmento.
- Usando a definição de ponto, o programa deve permitir definir (estrutura) triângulos, com
funções para ler, imprimir, verificar se o triângulo é válido, classifica-lo pelos lados, calcular o
perímetro e a área.
- O programa deve ler 10 pontos e encontrar quais dois pontos definem o menor segmento de
reta e quais três pontos o triângulo com maior área. Imprima a classificação, área e perímetro
desse triângulo.

Aluno: Matheus Almeida Silva - 316326
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
    float x;
    float y;
} pont, *ptrpont;

typedef struct reta {
    pont p1;
    pont p2;
} ret, *ptrret;

typedef struct triangulo {
    pont p1;
    pont p2;
    pont p3;
} tria, *ptrtria;

void leitura_ponto(ptrpont ponto){                //Função que realiza a leitura de um numero complexo z em coordenada cartesiana
    printf("Informe o ponto no formato (x,y), inserindo valor em x e em y: ");
    scanf("%f %f", &ponto->x, &ponto->y);
}

void exibe_ponto (pont ponto){
    printf("O ponto eh: (%2.f,%2.f)\n", ponto.x, ponto.y);
}

