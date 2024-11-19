#include "tabuleiro.h"

tTabuleiro CriaTabuleiro(){
    int i = 0, j = 0;
    tTabuleiro tabuleiro;

    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }

    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    tabuleiro.posicoes[x][y] = peca;
    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int i = 0, j = 0;

    for(i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if(tabuleiro.posicoes[i][j] == tabuleiro.pecaVazio){
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if(tabuleiro.posicoes[x][y] == peca){
        return 1;
    }
    else {
        return 0;
    }
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    if(tabuleiro.posicoes[x][y] == tabuleiro.pecaVazio){
        return 1;
    }
    else {
        return 0;
    }
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if(x >= 0 && x <= 3 && y >= 0 && y <= 3){
        return 1;
    }
    else {
        return 0;
    }
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int i = 0, j = 0;
    for (i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
    return 0;
}


