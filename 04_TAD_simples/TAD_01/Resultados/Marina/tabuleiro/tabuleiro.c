#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro(){
    int i = 0, j = 0;
    tTabuleiro tabuleiro;

    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';

    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }

    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    if(peca == 1){
        peca = 'X';
    }
    else if(peca == 2){
        peca = '0';
    }
    //if (EstaLivrePosicaoTabuleiro(tabuleiro, x, y) && EhPosicaoValidaTabuleiro(x,y)){
    tabuleiro.posicoes[y][x] = peca;
    //}
    
    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int i = 0, j = 0;

    for(i = 0; i < TAM_TABULEIRO; i++){
        for (j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro.posicoes[i][j] == tabuleiro.pecaVazio){
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if(peca == 1){
        peca = 'X';
    }
    else if(peca == 2){
        peca = '0';
    }
    if(tabuleiro.posicoes[y][x] == peca){
        return 1;
    }
    else {
        return 0;
    }
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    
    if(tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio){
        return 1;
    }
    else {
        return 0;
    }
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if(x >= 0 && x < 3 && y >= 0 && y < 3){
        return 1;
    }
    else {
        return 0;
    }
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int i = 0, j = 0;

    int vazio = 1;

    for (i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,i ,j , 1) || EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,i ,j ,2 )){
                vazio = 0;
                break;
            }
        }
    }
    if(vazio == 0){
        for (i = 0; i < TAM_TABULEIRO; i++){
        printf("\t");
        for(j = 0; j < TAM_TABULEIRO; j++){
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
        }
    }

    return;
}


