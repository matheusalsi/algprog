#include <stdio.h>
#include <string.h>


#include <stdio.h>
#include <string.h>

int main(){
    char nome[100001];
    int i, aux = 0;
    scanf("%s", nome);

    for (i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == 'z' || nome[i] == 'Z'){
            if((nome[i+1] == 'e' || nome[i+1] == 'E') && (nome[i+2] == 'l' || nome[i+2] == 'L') && (nome[i+3] == 'd' || nome[i+3] == 'D') && (nome[i+4] == 'a' || nome[i+4] == 'A')){
                aux = 1;
                break;
            }
        }
    }

    if(aux == 1) {
		printf("Link Bolado\n");
	} else {
		printf("Link Tranquilo\n");
	}

    return 0;

}




