#include <stdio.h>
#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"


tJogador CriaJogador(int idJogador){
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}


tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jogada;
    int peca = jogador.id;
    jogada = LeJogada();
    tabuleiro =  MarcaPosicaoTabuleiro(tabuleiro, peca, jogada.x, jogada.y);
    return tabuleiro;
}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    char peca = 'a';
    if(jogador.id == 1){
        peca = 'X';
    }
    else if(jogador.id == 2){
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
