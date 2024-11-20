#include "jogada.h"
#include <stdio.h>

tJogada LeJogada(){
    tJogada jogada;
    int ret  = 0;
    int x = 0, y = 0;
    printf("Digite uma posicao (x e y):\n");
    ret = scanf("%d %d", &x, &y);

    if(ret == 2){
        jogada.x = x;
        jogada.y = y;
        jogada.sucesso = 1;
    }
    else {
        jogada.x = x;
        jogada.y = y;
        jogada.sucesso = 0;
    }
    return jogada;
}

int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada){
    return jogada.sucesso;
}

