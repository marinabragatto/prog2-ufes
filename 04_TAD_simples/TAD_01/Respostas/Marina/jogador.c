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
    int false = 0;
    
    if(tabuleiro.posicoes[0][0] == jogador.id && tabuleiro.posicoes[0][2] == jogador.id && tabuleiro.posicoes[0][1] == jogador.id){

    }
    false = 1;
    for(i = 0; i < 3; i++){
        if(tabuleiro.posicoes[0][i] != jogador.id){
            false = 0;
        }
    }
    if(false == 1){
        return 1; 
    }

}
