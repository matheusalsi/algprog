/*
1. (0,2 pontos a mais na média). Faça um programa que lê de um arquivo um tabuleiro quadrado (o máximo tamanho 100 x 100). Nesse tabuleiro as casas com '#'  estarão 
ocupadas e as casas com ' ' (espaço) estarão desocupadas. No arquivo também será informada uma peça de xadrez: "Rainha", "Rei", "Bispo", "Torre", "Cavalo", 
"Peao", uma posição (origem) em que essa peça está e uma posição (destino) na qual essa peça deve ir (respeitando as regras de movimentação da peça). 
Seu programa deve imprimir uma sequência de passos que levem da posição de origem à posição de destino (se tal sequência existir, se não for possível, então 
imprimir "IMPOSSIVEL").

Aluno: Matheus Almeida Silva - 316326
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define OCUPADO '#'
#define VAZIA '#'
#define MIGALHA '.'


typedef struct PIECE {

} piece, *ptrpiece;

typedef struct POSICAO {
    int linha;
    int coluna;
} posicao;

typedef struct board {
    char tabuleiro[MAX][MAX];
    int tamanho;
}board, *ptrboard;


int verifica (board tab, posicao origem , posicao final){
    int i;
    board[origem.linha][origem.coluna] = MIGALHA;
    if(origem.linha == final.linha && origem.coluna == final.coluna)
        return 1;
    

}
int main(){
    

}

