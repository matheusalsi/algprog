/*
4. (2 pontos) Números complexos. Faça um programa que trabalhe com números complexos:
- O programa deve possuir duas definições diferentes para números complexos: a cartesiana
(retangular) e a polar. (em estruturas separadas).
- O programa deve possuir uma função que converta de representação polar para cartesiana e
outra que converta de cartesiana para polar.
- O programa deve possuir funções que permitam somar, subtrair, multiplicar e dividir números
em ambas as representações.
- O programa deve ter um menu para selecionar a operação a ser realizada ou sair. Caso a
operação não seja sair, perguntar em qual representação se informação os números, ler os
números e imprimir a resposta da operação em ambas as representações.

Aluno: Matheus Almeida Silva - 316326
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct cartesiana { // Struct que armazena os dados da definição cartesiana
    double a;
    double b;
}cart, *ptrcart;

typedef struct polar {  // Struct que armazena os dados da definição polar
    double p;
    double angulo;
}pol, *ptrpol;

void leitura_retangular(ptrcart numero){                //Função que realiza a leitura de um numero complexo z em coordenada cartesiana
    printf("Informe o coeficiente a da parte real para z = a + bi: ");
    scanf("%lf", &numero->a);
    printf("Informe o coeficiente b da parte imaginaria para z = a + bi: ");
    scanf("%lf", &numero->b);
}

void leitura_polar(ptrpol numero){                      //Função que realiza a leitura de um numero complexo z em coordenada polar
    printf("Informe o modulo p para z = p(cosR + sinRi): ");
    scanf("%lf", &numero->p);
    printf("Informe o angulo R em radianos para z = p(cosR + sinRi): ");
    scanf("%lf", &numero->angulo);

}

cart converte_polar_para_retangular(pol numero){        //Função que converte um complexo polar em retangular retornando esse complexo em coordenada cartesiana
    cart retangular_convertido;
    retangular_convertido.a = numero.p * cos(numero.angulo);
    retangular_convertido.b = numero.p * sin(numero.angulo);
    return retangular_convertido;
}

pol converte_rentangular_para_polar(cart numero){      //Função que converte um complexo retangular em polar retornando esse complexo em coordenada polar
    pol polar_convertido;
    polar_convertido.p = sqrt(pow(numero.a,2) + pow(numero.b,2));
    polar_convertido.angulo  = atan2(numero.b,numero.a);
    return polar_convertido;
}

/*As duas funções abaixo exibem o numero complexo em sua definição retangular ou polar*/

void exibe_retangular (cart numero){
    printf("A representacao retangular: z = %.2lf + %.2lfi\n", numero.a, numero.b);
}

void exibe_polar (pol numero){
    printf("A representacao polar: z = %.2lf(cos(%.2lf) + sin(%.2lf)i\n", numero.p, numero.angulo, numero.angulo);
}

cart soma (cart numero1, cart numero2){    // Função que recebe um complexo em coordenadas cartesianas e realiza sua soma
    cart valor_soma;
    valor_soma.a = numero1.a + numero2.a;
    valor_soma.b = numero1.b + numero2.b;
    return valor_soma;

}

cart subtrai (cart numero1, cart numero2){    // Função que recebe um complexo em coordenadas cartesianas e realiza sua subtração
    cart subtracao;
    subtracao.a = numero1.a - numero2.a;
    subtracao.b = numero1.b - numero2.b;
    return subtracao;

}

cart multiplica (cart numero1, cart numero2){ // Função que recebe um complexo em coordenadas cartesianas e realiza sua multiplicação
    cart produto;
    produto.a = (numero1.a*numero2.a) - (numero1.b*numero2.b);
    produto.b = (numero1.a*numero2.b) + (numero1.b*numero2.a);
    return produto;
}

cart divide (cart numero1, cart numero2) {  // Função que recebe um complexo em coordenadas cartesianas e realiza sua divisão
    cart divisao;
    divisao.a = (numero1.a*numero2.a + numero1.b*numero2.b)/(pow(numero2.a,2)+pow(numero2.b,2));
    divisao.b = (numero1.b*numero2.a - numero1.a*numero2.b)/(pow(numero2.a,2)+pow(numero2.b,2));
    return divisao;
}

void limpa(char * texto) {              // Função que limpa a tela e recebe um texto a ser exibido
    system("cls");
    printf("%s\n\n", texto);
}

void aguarda() {                        //Função que define um operador e enquanto não receber 0(falso) realiza um loop para aguardar a exibição da tela
    int op;
    do {
        printf("\nPara voltar ao menu anterior digite 0\n");
        scanf("%d", &op);
    }while(op);
}

int verifica_reprentacao (){            //Função que veirifica em qual representação os numeros serão lidos, retornando um inteiro para cada operação
    int repr;
    printf("\nQual a representacao dos numeros:\n 1 - Retangular\n 2 - Polar\n");
    scanf("%d", &repr);
    switch (repr) {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        default:
            limpa("Opcao Invalida!!!\n");
            aguarda();
            break;
    }
}

/*  **Comentários gerais sobre a main**
A main define 3 inteiros op,sair e v. 
E 2 vetores de tamanho 2 para receberem os complexos em cada coordenada.
Sendo op o operador para definir a operação do menu, sair um inteiro 0 a ser utilizando como opção de saida do menu e v como o retorno da verificação.
O programa realiza um loop para o menu que é executado enquanto no primeiro menu de opções não for computado como 1.
Cada caso de 1 a 4 opera de forma similar:
-definindo duas variaveis em cada coordenada para receberem o resultado da operação a ser realizada;
-realizando um loop para a leitura na variavel informada
-No caso v == 2, onde se recebe uma variavel polar, o programa converte e outro vetor recebe os valores já convertidos.
-Realiza-se a operação(soma,subtração,multiplicação e divisão) com sua respectiva função recebendo sempre o numero complexo em sua forma retangular.
-O resultado é convertido e armazenado em outra variavel em sua forma polar
-Por último exibe-se o resultado complexo em suas duas definições
No caso 5 o sair recebe 1 e portanto define a última operação do while.
Caso o switch não recebe nenhum numero válida, o default informa que a operação é inválida, limpa a tela e aguarda o retorno para o menu inicial.
*/

int main () {   //Função principal que realiza o menu principal e as operações para cada caso
    int op, sair = 0;
    int v;
    pol polar[2];
    cart retangular[2];

    do {
        limpa("Escolha uma opcao:\n 1 - Soma\n 2 - Subtracao\n 3 - Multiplicacao\n 4 - Divisao\n 5- Sair\n");
        scanf("%d", &op);
        getchar();
        switch(op) {
            case 1:
                v = verifica_reprentacao();
                if (v == 1) {
                    cart resultc;
                    pol resultp;
                    for (int i = 0; i < 2; i++) {
                        leitura_retangular(retangular + i);
                    }
                    resultc = soma(retangular[0], retangular[1]);
                    resultp = converte_rentangular_para_polar(resultc);
                    printf("O resultado da soma eh:\n");
                    exibe_retangular(resultc);
                    exibe_polar(resultp);
                    
                }
                if (v == 2) {
                    cart resultc;
                    pol resultp;
                    for (int i = 0; i < 2; i++) {
                        leitura_polar(polar + i);
                        retangular[i] = converte_polar_para_retangular(polar[i]);
                    }
                    resultc = soma(retangular[0], retangular[1]);
                    resultp = converte_rentangular_para_polar(resultc);
                    printf("O resultado da soma eh:\n");
                    exibe_retangular(resultc);
                    exibe_polar(resultp);
                }
                aguarda();
                break;
            case 2:
                v = verifica_reprentacao();
                if (v == 1) {
                    cart resultc;
                    pol resultp;
                    for (int i = 0; i < 2; i++) {
                        leitura_retangular(retangular + i);
                    }
                    resultc = subtrai(retangular[0], retangular[1]);
                    resultp = converte_rentangular_para_polar(resultc);
                    printf("O resultado da subtracao eh:\n");
                    exibe_retangular(resultc);
                    exibe_polar(resultp);
                }
                if (v == 2) {
                    cart resultc;
                    pol resultp;
                    for (int i = 0; i < 2; i++) {
                        leitura_polar(polar + i);
                        retangular[i] = converte_polar_para_retangular(polar[i]);
                    }
                    resultc = subtrai(retangular[0], retangular[1]);
                    resultp = converte_rentangular_para_polar(resultc);
                    printf("O resultado da subtracao eh:\n");
                    exibe_retangular(resultc);
                    exibe_polar(resultp);
                }
                aguarda();
                break;
            case 3:
                v = verifica_reprentacao();
                if (v == 1) {
                    cart resultc;
                    pol resultp;
                    for (int i = 0; i < 2; i++) {
                        leitura_retangular(retangular + i);
                    }
                    resultc = multiplica(retangular[0], retangular[1]);
                    resultp = converte_rentangular_para_polar(resultc);
                    printf("O resultado da multiplicacao eh:\n");
                    exibe_retangular(resultc);
                    exibe_polar(resultp);
                }
                if (v == 2) {
                    cart resultc;
                    pol resultp;
                    for (int i = 0; i < 2; i++) {
                        leitura_polar(polar + i);
                        retangular[i] = converte_polar_para_retangular(polar[i]);
                    }
                    resultc = multiplica(retangular[0], retangular[1]);
                    resultp = converte_rentangular_para_polar(resultc);
                    printf("O resultado da multiplicacao eh:\n");
                    exibe_retangular(resultc);
                    exibe_polar(resultp);
                }
                aguarda();
                break;
            case 4:
                v = verifica_reprentacao();
                if (v == 1) {
                    cart resultc;
                    pol resultp;
                    for (int i = 0; i < 2; i++) {
                        leitura_retangular(retangular + i);
                    }
                    resultc = divide(retangular[0], retangular[1]);
                    resultp = converte_rentangular_para_polar(resultc);
                    printf("O resultado da divisao eh:\n");
                    exibe_retangular(resultc);
                    exibe_polar(resultp);
                }
                if (v == 2) {
                    cart resultc;
                    pol resultp;
                    for (int i = 0; i < 2; i++) {
                        leitura_polar(polar + i);
                        retangular[i] = converte_polar_para_retangular(polar[i]);
                    }
                    resultc = divide(retangular[0], retangular[1]);
                    resultp = converte_rentangular_para_polar(resultc);
                    printf("O resultado da divisao eh:\n");
                    exibe_retangular(resultc);
                    exibe_polar(resultp);
                }
                aguarda();
                break;
            case 5:
                sair = 1;
                break;
            default:
                limpa("Opcao Invalida!!!\n");
                aguarda();
        }
    }while(!sair);

    return 0;
}