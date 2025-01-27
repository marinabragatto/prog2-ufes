#include "jogo.h"

//typedef struct{
//    tTabuleiro* tabuleiro;
//    tJogador* jogador1;
//    tJogador* jogador2;
//} tJogo;

/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo* CriaJogo(){
    tJogo *jogo;
    jogo = (tJogo*)malloc(sizeof(tJogo));
    
    return;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo* jogo){
    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo->jogador2 = CriaJogador(ID_JOGADOR_2);

    
        while(1){
            if(AcabouJogo(jogo)){
                printf("Sem vencedor!\n");
                break;
            }
            JogaJogador(jogo->jogador1, jogo->tabuleiro);
            ImprimeTabuleiro(jogo->tabuleiro);
            if(VenceuJogador(jogo->jogador1, jogo->tabuleiro)){
                printf("JOGADOR 1 Venceu!\n");
                break;
            }
            if(AcabouJogo(jogo)){
                printf("Sem vencedor!\n");
                break;
            }
            JogaJogador(jogo->jogador2, jogo->tabuleiro);
            ImprimeTabuleiro(jogo->tabuleiro);
            if(VenceuJogador(jogo->jogador2, jogo->tabuleiro)){
                printf("JOGADOR 2 Venceu!\n");
                break;
            }
        }
        
    DestroiTabuleiro(jogo->tabuleiro);
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);
    return;
}


/**9
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
    else{
        return 0;
    }

}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo(){
    char opcao = 'a';
    printf("Jogar novamente? (s,n)\n");
    scanf("%*[^sn]");
    scanf("%c", &opcao);
    if(opcao == 's'){
        return 1;
    }
    else if(opcao == 'n'){
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
        free(jogo);
    }
    else {
        printf("falha na alocacao do jogo");
        exit(1);
    }
}