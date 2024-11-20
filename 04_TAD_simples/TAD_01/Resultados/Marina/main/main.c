#include "jogada.h"
#include "tabuleiro.h"
#include "jogo.h"
#include "jogador.h"
#include <stdio.h>

int main(){
    tJogo jogo;
    while(1){
        jogo = CriaJogo();
        ComecaJogo(jogo);
        if(!ContinuaJogo()){
            break;
        }
    }
    
    return 0;
}
