/*
VERSÃO ARQUIVO DE TEXTO!
4.Em uma das salas do instituto aparecem goteiras sempre que chega o período de chuvas. Particularmente, uma goteira aparece em uma das paredes da sala que tem 
várias prateleiras horizontais. Essa goteira faz a água escorrer verticalmente, a partir de um ponto no teto e, quando a água bate em uma prateleira, ela começa 
escorrer horizontalmente para os dois lados lados até as extremidades da prateleira, de onde volta a escorrer verticalmente. A parede pode ser apresentada por uma 
matriz de até 100 linhas e até 100 colunas, onde cada casa tem um '.' indicando que está vazia, um 'o' indicando água que escorre ou um '#' indicando que tem prateleira.
Um exemplo de parede, com 9 linhas e 14 colunas é a imagem no arquivo exemplo_parede.png.

-Faça uma estrutura para representar a parede e um programa que, pede os dados da estrutura para o usuário e a armazena no arquivo parede.in.
-Faça outro programa que leia a parede de parede.in e imprima a matriz com as posições que serão molhadas, salvando essa nova matriz em parede.out. As posições que serão 
molhadas se representam com 'o' e seguem a seguinte regra (o arquivo exemplo_parede_molhada.png mostra como ficaria o exemplo do arquivo exemplo_parede.png com as posições molhadas):
    -Posições molhadas (com 'o') ficam molhadas (com 'o').
    -Posições com prateleira (com '#') não ficam molhadas, ficam com a prateleira (com '#').
    -Uma posição vazia (com '.') na linha i e coluna j fica molhada se:
        -A posição na linha i-1 e a coluna j está molhada (tem 'o'); ou
        -A posição na linha i+1 e a coluna j-1 tem prateleira ('#') e a posição na linha i e a coluna j-1 está molhada (tem 'o'); ou
        -A posição na linha i+1 e a coluna j+1 tem prateleira ('#') e a posição na linha i e a coluna j+1 está molhada (tem 'o').

Matheus Almeida Silva - 316326
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>