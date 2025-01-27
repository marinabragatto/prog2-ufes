#include "tabuleiro.h"

char ** criaMatrizTabuleiro();
void preencherPosicoes(char ** posicoes);
void destroiPosicoes(char ** posicoes);

//typedef struct{
//    char** posicoes;
//    char peca1;
//    char peca2;
//    char pecaVazio;
//} tTabuleiro;

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro* CriaTabuleiro(){
    tTabuleiro * tabuleiro;
    tabuleiro = (tTabuleiro *)malloc(sizeof(tTabuleiro));
    if(!tabuleiro){
        printf("erro ao alocar");
        exit(1);
    }
    tabuleiro->peca1 = 'X';
    tabuleiro->peca2 = '0';
    tabuleiro->pecaVazio = '-';
    tabuleiro->posicoes = criaMatrizTabuleiro();
    int i = 0, j = 0;
    for (i = 0 ; i< 3; i++){
        for(j = 0 ; j < 3; j++){
            tabuleiro->posicoes[i][j] = tabuleiro->pecaVazio; 
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
        destroiPosicoes(tabuleiro->posicoes);
        free(tabuleiro);
    }
    else{
        printf("tentou liberar vetor nulo");
        exit(1);
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
        tabuleiro->posicoes[y][x] = tabuleiro->peca1;
    }
    else if(peca == PECA_2){
        tabuleiro->posicoes[y][x] = tabuleiro->peca2;
    }

    


    return;
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){
    int i = 0, j = 0;

    for (i = 0 ; i< 3; i++){
        for(j = 0 ; j < 3; j++){
            if(tabuleiro->posicoes[i][j] == tabuleiro->pecaVazio){
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
    if(peca == 1){
        if(tabuleiro->posicoes[y][x] == tabuleiro->peca1){
            return 1;
        }
        else {
            return 0;
        }
    }else if(peca == 2){
        if(tabuleiro->posicoes[y][x] == tabuleiro->peca2){
            return 1;
        }
        else {
            return 0;
        }
    }
    
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
    if(tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio){
        return 1;
    }
    else {
        return 0;
    }
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
    else {
        return 0;
    }
}


/**
 * Imprime o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro* tabuleiro){
    int i = 0, j = 0;
    for (i = 0 ; i< 3; i++){
        printf("\t");
        for(j = 0 ; j < 3; j++){
            printf("%c", tabuleiro->posicoes[i][j]);
        }
        printf("\n");
    }

}

char ** criaMatrizTabuleiro(){
    char **ptrLinhas;
    int i = 0;
    ptrLinhas = (char**)malloc(sizeof(char*)*3);
    if(!ptrLinhas){
        printf("erro ao alocar matriz posicoes");
        exit(1);
    }
    
    for(i = 0; i < 3; i++){
        ptrLinhas[i] = (char*)malloc(sizeof(char)*3);
        if(!ptrLinhas[i]){
            printf("erro ao alocar colunas");
            exit(1);
        }
    }
    return ptrLinhas;
}

void destroiPosicoes(char ** posicoes){
    int i = 0;
    if(posicoes){
        for(i = 0 ; i < 3; i++){
            if(posicoes[i]){
                free(posicoes[i]);
            }
            else{
                printf("tentou liberar ponteiro nulo\n");
                exit(1);
            }
        }
        free(posicoes);
    }
    else{
        printf("tentou liberar ponteiro nulo");
    }
    
}



