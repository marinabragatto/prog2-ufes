
#include "jogada.h"

tJogada LeJogada(){
    tJogada jogada;
    int ret  = 0;
    ret = scanf("%d %d", &jogada.x, &jogada.y);
    if(ret == 2){
        jogada.sucesso = 1;
    }
    else {
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
    if(jogada.sucesso == 1){
        return 1;
    }
    else {
        return 0;
    }
}

