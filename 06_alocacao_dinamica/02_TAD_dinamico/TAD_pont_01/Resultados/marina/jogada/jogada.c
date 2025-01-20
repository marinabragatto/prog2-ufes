#include "jogada.h"

//typedef struct{
  //  int x;
 //   int y;
//    int sucesso;
//} tJogada;

/**
 * Aloca e retorna uma estrutura do tipo tJogada.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogada alocada.
 */
tJogada* CriaJogada(){
    tJogada *jogadaPtr;
    
    jogadaPtr = (tJogada*)malloc(sizeof(tJogada));
    jogadaPtr->x = -1;
    jogadaPtr->y = -1;
    jogadaPtr->sucesso = 0;
    return jogadaPtr;
}


/**
 * Libera a memória de uma estrutura do tipo tJogada.
 * 
 * @param jogada a estrutura do tipo tJogada a ser liberada.
 */
void DestroiJogada(tJogada* jogada){
    if(jogada){
        free(jogada);
    }
    else{
        printf("tentou liberar ponteiro jogada ja nulo");
        exit(1);
    }
}


/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogada a estrutura do tipo tJogada a ser preenchida.
 */
void LeJogada(tJogada* jogada){
    int x = 0, y = 0;
    
    //while(1){
        printf("Digite uma posicao (x e y):\n");
        scanf("%d %d", &x, &y);
    
        if(x >= 0 && x <= 2 && y >= 0 && y <= 2 ){
            
            jogada->x = x;
            jogada->y = y;
            jogada->sucesso = 1;
           // break;
        }
        else{
            jogada->x = 2;
            jogada->y = 2;
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x,y);

            jogada->sucesso = 0;
        }
    //}
    
    return;
}


/**
 * Retorna a coordenada X da jogada.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return a coordenada X da jogada.
 */
int ObtemJogadaX(tJogada* jogada){
    return jogada->x;
}


/**
 * Retorna a coordenada Y da jogada.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return a coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada* jogada){
    return jogada->y;
}

/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada* jogada){
    if(jogada->sucesso){
        return 1;
    }
    else {
        return 0;
    }
}