#include <stdio.h>
#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"
#include "jogo.h"


tJogador CriaJogador(int idJogador){
    tJogador jogador = {0};
    jogador.id = idJogador;
    return jogador;
}


tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    while (1){
        printf("Jogador %d\n", jogador.id);
        tJogada jogada = {-1, -1, -1};
        int x = 0, y = 0;
        jogada = LeJogada();
        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);

        if(EhPosicaoValidaTabuleiro(x,y) && EstaLivrePosicaoTabuleiro(tabuleiro, x, y)){
            printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            tabuleiro =  MarcaPosicaoTabuleiro(tabuleiro, jogador.id, jogada.x, jogada.y);
            break;
            
        }
        else if(!(EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) && EhPosicaoValidaTabuleiro(x, y)){
        
        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
                        
        }
        else {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
        }
    }
    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    char peca = 'a';

    if(jogador.id == 1){
        peca = 'X';
    }
    else {
        peca = '0';
    }

    if(tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[0][2] == peca && tabuleiro.posicoes[0][1] == peca){
        return 1;
    }
    if(tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[1][0] == peca && tabuleiro.posicoes[2][0] == peca){
        return 1;
    }
    if(tabuleiro.posicoes[0][1] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][1] == peca){
        return 1;
    }
    if(tabuleiro.posicoes[0][2] == peca && tabuleiro.posicoes[1][2] == peca && tabuleiro.posicoes[2][2] == peca){
        return 1;
    }
    if(tabuleiro.posicoes[1][0] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[1][2] == peca){
        return 1;
    }
    if(tabuleiro.posicoes[2][0] == peca && tabuleiro.posicoes[2][1] == peca && tabuleiro.posicoes[2][2] == peca){
        return 1;
    }
    if(tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][2] == peca){
        return 1;
    }
    if(tabuleiro.posicoes[0][2] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][0] == peca){
        return 1;
    }
    return 0;
}
