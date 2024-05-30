#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fogo, agua, gelo, terra, eletrico

#define FOGO "fogo" // ganha gelo
#define AGUA "agua" // ganha do fogo, terra
#define GELO "gelo" // ganha eletrico, terra
#define TERRA "terra" // ganha fogo, eletrico
#define ELETRICO "eletrico" // ganha agua

#define MAX 100

#define ARQUIVO "pokemon.bin"

typedef struct POKEMON {
    char nome[21];
    char tipo[11];
    int forca;
} Pokemon, * pPokemon;


int salva(pPokemon p, int n) {
    FILE * arquivo;
    if(arquivo = fopen(ARQUIVO, "wb")) {
        fwrite(&n, sizeof(int), 1, arquivo);
        fwrite(p, sizeof(Pokemon), n, arquivo);
        fclose(arquivo);
        return 1;
    } else
        return 0;
}

int abre(Pokemon * p) {
    FILE * arquivo = fopen(ARQUIVO, "rb");
    int n = 0;
    if(arquivo) {
        fread(&n, sizeof(int), 1, arquivo);
        fread(p, sizeof(Pokemon), n, arquivo);
        fclose(arquivo);
        return n;
    } else
        return -1;

}


int ganha(char * tipo1, char * tipo2) {
    if(strcmp(tipo1, FOGO) == 0)
        return strcmp(tipo2, GELO) == 0;
    if(strcmp(tipo1, AGUA) == 0)
        return strcmp(tipo2, FOGO) == 0 || strcmp(tipo2, TERRA);
    if(strcmp(tipo1, GELO) == 0)
        return strcmp(tipo2, ELETRICO) == 0 || strcmp(tipo2, TERRA);
    if(strcmp(tipo1, TERRA) == 0)
        return strcmp(tipo2, ELETRICO) == 0 || strcmp(tipo2, FOGO);
    if(strcmp(tipo1, ELETRICO) == 0)
        return strcmp(tipo2, AGUA) == 0;
    return 0;
}


// P1 ganha de P2 se: P1 tem um tipo que ganha do tipo de P2 e for�a maior ou igual que a metade de P2.
//Se o tipo de P1 n�o ganha, mas a for�a � maior que a metade de P2, ent�o ganha


int melhor(Pokemon p1, Pokemon p2) {
    if(ganha(strlwr(p1.tipo), strlwr(p2.tipo)))
        return p1.forca > p2.forca / 2;
    else if(ganha(strlwr(p2.tipo), strlwr(p1.tipo)))
        return p1.forca > 2 * p2.forca;
    return p1.forca > p2.forca;
}

void le(pPokemon p) {
    puts("Indique o nome do pokemon:");
    gets(p->nome);
    puts("Indique o tipo do pokemon:");
    gets(p->tipo);
    puts("Indique a forca:");
    scanf("%d", & (p->forca));
}

void imprime(Pokemon p) {
    printf("pokemon %s eh de tipo %s e tem forca %d\n", p.nome, p.tipo, p.forca);
}

void imprime_todos(pPokemon primeiro, int n) {
    pPokemon atual;
    for(atual = primeiro; primeiro + n != atual; atual++) {
        printf(" - ");
        imprime(*atual);
    }
}

void imprime_melhores(Pokemon p, pPokemon primeiro, int n) {
    pPokemon atual;
    for(atual = primeiro; primeiro + n != atual; atual++)
        if(melhor(*atual, p)) {
            printf(" - ");
            imprime(*atual);
        }
}

void limpa(char * texto) {
    system("cls");
    printf("%s\n\n", texto);
}

void aguarda() {
    int op;
    do {
        printf("\nPara voltar ao menu principal digite 0\n");
        scanf("%d", &op);
    }while(op);
}

int main() {
    Pokemon lista[MAX], p;
    int n = 0;
    int op, sair = 0, aux;
    do {
        limpa("Escolha uma opcao:\n 1- Adicionar pokemon\n 2- Listar pokemons\n 3- Consultar melhores\n 4- Salvar\n 5- Abrir\n 6- Sair\n");
        scanf("%d", &op);
        getchar();
        switch(op) {
            case 1:
                limpa("Adicionando Pokemon\n");
                if(n < MAX) {
                    le(lista + n);
                    n ++;
                } else
                    printf("Lista cheia!!!\n");
                aguarda();
                break;
            case 2:
                limpa("Lista de pokemons\n");
                imprime_todos(lista, n);
                aguarda();
                break;
            case 3:
                le(&p);
                limpa("Consulta");
                printf("Ganham de ");
                imprime(p);
                imprime_melhores(p, lista, n);
                aguarda();
                break;
            case 4:
                if(salva(lista, n))
                    limpa("Pokemons salvos com sucesso!!!");
                else
                    limpa("Erro ao salvar os pokemons!!!");
                aguarda();
                break;
            case 5:
                aux = abre(lista);
                if(aux >= 0) {
                    limpa("Pokemons lidos!\n");
                    n = aux;
                    imprime_todos(lista, n);
                } else
                    limpa("Erro ao abrir o arquivo!!");
                aguarda();
                break;
            case 6:
                sair = 1;
                break;
            default:
                limpa("Opcao Invalida!!!\n");
                aguarda();
        }
    }while(!sair);

    printf("Adeus!!\n");
    return 0;
}

