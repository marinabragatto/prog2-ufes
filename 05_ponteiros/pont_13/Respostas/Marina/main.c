#include <stdio.h>
#include "rolagem.h"

int main(){
    int qtd = 0, i = 0, tempo = 0;

    scanf("%d", &qtd);
    char msg[NUM_MAX_MSGS][TAM_MAX_MSG];

    for(i = 0; i < qtd;i++){
        scanf("%d%999s\n", msg[i]);
    }

    scanf("%d", &tempo);
    RolaMsg()
}