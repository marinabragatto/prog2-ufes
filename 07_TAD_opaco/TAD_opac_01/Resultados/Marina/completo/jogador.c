#include "jogador.h"
#include "jogada.h"

//#define ID_JOGADOR_1 1
//#define ID_JOGADOR_2 2

struct Jogador {
    int id;
};


/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 * 
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador* CriaJogador(int idJogador){
    tJogador *jogador;
    jogador = (tJogador*)malloc(sizeof(tJogador));
    jogador->id = idJogador;
    return jogador;
}


/**
 * Libera a memória de uma estrutura do tipo tJogador.
 * 
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador* jogador){
    if(jogador){
        free(jogador);
    }
}


/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro){    
    int x = 0 , y = 0;
    tJogada * jogada;

    jogada = CriaJogada();

    while(1){
        printf("Jogador %d\n", jogador->id);
        LeJogada(jogada);
        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);
        

        if(!EhPosicaoValidaTabuleiro(x, y)){
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n",x,y);
            continue;
        }
        else if(!EstaLivrePosicaoTabuleiro(tabuleiro,x,y)){
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n",x,y);
            continue;
        }
        else if(FoiJogadaBemSucedida(jogada)){
            printf("Jogada [%d,%d]!\n", x, y);
            MarcaPosicaoTabuleiro(tabuleiro, jogador->id, x, y);
            break;
        }
    }

    DestroiJogada(jogada);
}


/**
 * Verifica se o jogador venceu o jogo.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    
    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, jogador->id)){
        return 1;
    }
    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, jogador->id)){
        return 1;
    }
    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, jogador->id)){
        return 1;
    }
    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, jogador->id)){
        return 1;
    }
    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, jogador->id)){
        return 1;
    }
    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, jogador->id)){
        return 1;
    }
    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, jogador->id)){
        return 1;
    }
    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador->id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, jogador->id)){
        return 1;
    }
    return 0;
}