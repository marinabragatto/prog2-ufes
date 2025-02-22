#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

//#define PECA_1 1
//#define PECA_2 2

struct Tabuleiro {
    char **data;

};


/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro* CriaTabuleiro(){
    int i = 0, j = 0;
    
    tTabuleiro * tabuleiro;
    tabuleiro = (tTabuleiro*)malloc(sizeof(tTabuleiro));
    
    tabuleiro->data = (char**)malloc(sizeof(char*)*TAM_TABULEIRO);
    
    for(i = 0; i < TAM_TABULEIRO; i++){
        tabuleiro->data[i] = (char*)malloc((sizeof(char)*TAM_TABULEIRO));
    }

 
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro->data[i][j] = '-';
        }
    }

    return tabuleiro;
}


/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 * 
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro* tabuleiro){
    if(tabuleiro){
        int i = 0;
        if(tabuleiro->data){
            for(i = 0; i < TAM_TABULEIRO; i++){
                if(tabuleiro->data[i]){
                    free(tabuleiro->data[i]);
                }
            }
            free(tabuleiro->data);
        }
            
        free(tabuleiro);
    }
}


/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y){
    if(peca == PECA_1){
        tabuleiro->data[y][x] = 'X';
    }
    else {
        tabuleiro->data[y][x] = '0';
    }
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){
    int j = 0, i = 0;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro->data[i][j] == '-'){
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca){
    if(peca == PECA_1){
        if(tabuleiro->data[y][x] == 'X'){
            return 1;
        }
        else {
            return 0;
        }
    }else if(peca == PECA_2){
        if(tabuleiro->data[y][x] == '0'){
            return 1;
        }
        else {
            return 0;
        }
    }

    return 0;
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){
    if(tabuleiro->data[y][x] == '-'){
        return 1;
    }
    return 0 ;
}


/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y){
    if(x >= 0 && x <= 2 && y >= 0 && y <= 2){
        return 1;
    }
    else{
        return 0;
    }

}


/**
 * Imprime o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro* tabuleiro){
    int j = 0, i = 0;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j=0; j < TAM_TABULEIRO; j++){
            printf("%c", tabuleiro->data[i][j]);
        }
        printf("\n");
    }
}