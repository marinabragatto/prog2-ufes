#include "jogo.h"
#include <stdlib.h>
#include <stdio.h>


struct Jogo {
    tTabuleiro  * tabuleiro;
    tJogador * p1,* p2;
};


/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo* CriaJogo(){
    tJogo * jogo;
    jogo = (tJogo*)malloc(sizeof(tJogo));
    if(!jogo){
        printf("erro na alocacao!\n");
        exit(1);
    }

    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo* jogo){
    jogo->tabuleiro = CriaTabuleiro();
    jogo->p1 = CriaJogador(ID_JOGADOR_1);
    jogo->p2 = CriaJogador(ID_JOGADOR_2);
    while(1){

        if(AcabouJogo(jogo)){
            printf("Sem vencedor!\n");
            return;
        }
        JogaJogador(jogo->p1, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);
        if(VenceuJogador(jogo->p1, jogo->tabuleiro)){
            printf("JOGADOR 1 Venceu!\n");
            return;
        }
       

        if(AcabouJogo(jogo)){
            printf("Sem vencedor!\n");
            return;
        }
        JogaJogador(jogo->p2, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);
        if(VenceuJogador(jogo->p2, jogo->tabuleiro)){
            printf("JOGADOR 2 Venceu!\n");
            return;
        }
    }
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo* jogo){
    if(!TemPosicaoLivreTabuleiro(jogo->tabuleiro)){
        return 1;
    }
    else {
        return 0;
    }
}



/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo(){
    char op = 'a';
    printf("Jogar novamente? (s,n)\n");
    scanf("%*[^sn]");
    scanf("%c", &op);
    if(op == 's'){
        return 1;
    }
    else if(op == 'n'){
        return 0;
    }
    return 0;
}


/**
 * Libera a memória de uma estrutura do tipo tJogo.
 * 
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo* jogo){
    if(jogo){
        if(jogo->tabuleiro){
            DestroiTabuleiro(jogo->tabuleiro);
        }
        if(jogo->p1){
            DestroiJogador(jogo->p1);
        }
        if(jogo->p2){
            DestroiJogador(jogo->p2);
        }
        free(jogo);
    }
}