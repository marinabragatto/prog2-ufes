#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"
#include "jogada.h"
#include <stdio.h>

tJogo CriaJogo(){
    tJogo jogo;
    jogo.jogador1 =  CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    jogo.tabuleiro = CriaTabuleiro();
    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo){
    while(1){
        jogo = CriaJogo();
        int atual = 0;
        while(1){
            if(atual%2 == 0){
                printf("Jogador 1\nDigite uma posicao (x e y):\n");
                tJogada jogada;
                jogada = LeJogada();
                int x = 0, y = 0;
                x = ObtemJogadaX(jogada);
                y = ObtemJogadaY(jogada);
                
        
                if(FoiJogadaBemSucedida(jogada) && EhPosicaoValidaTabuleiro(x, y) && EstaLivrePosicaoTabuleiro(jogo.tabuleiro, x, y)){
                    printf("Jogada [%d,%d]!\n", y, x);
                    jogo.tabuleiro = MarcaPosicaoTabuleiro(jogo.tabuleiro, 'X',ObtemJogadaX(jogada) , ObtemJogadaY(jogada));
                    ImprimeTabuleiro(jogo.tabuleiro);
                    atual++;
                    if(VenceuJogador(jogo.jogador1, jogo.tabuleiro)){
                        printf("JOGADOR 1 Venceu!\n");
                        break;
                    }
                }
                else{
                    if(!(EstaLivrePosicaoTabuleiro(jogo.tabuleiro, x, y)) && EhPosicaoValidaTabuleiro(x, y)){
                        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", y, x);
                        
                    }
                    else {
                        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", y, x);
                    }
                    
                
                }
            }
            else{
                printf("Jogador 2\nDigite uma posicao (x e y):\n");
                tJogada jogada;
                jogada = LeJogada();
                int x = 0, y = 0;
                x = ObtemJogadaX(jogada);
                y = ObtemJogadaY(jogada);
                
                if(FoiJogadaBemSucedida(jogada) && EhPosicaoValidaTabuleiro(x, y) && EstaLivrePosicaoTabuleiro(jogo.tabuleiro, x, y)){
                    printf("Jogada [%d,%d]!\n", y, x);
                    jogo.tabuleiro = MarcaPosicaoTabuleiro(jogo.tabuleiro, '0',ObtemJogadaX(jogada) , ObtemJogadaY(jogada));
                    ImprimeTabuleiro(jogo.tabuleiro);
                    atual++;
                    if(VenceuJogador(jogo.jogador2, jogo.tabuleiro)){
                        printf("JOGADOR 2 Venceu!\n");
                        break;
                    }
                }
                else{
                    if(!(EstaLivrePosicaoTabuleiro(jogo.tabuleiro, x, y)) &&EhPosicaoValidaTabuleiro(x, y)){
                       printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", y, x);
                        
                    }
                    else {
                        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", y, x);
                        
                    }
                
                }
            }
           
            
            if(AcabouJogo(jogo)){
                printf("Sem vencedor!\n");
                break;
            }
        }
        if(ContinuaJogo()){
            continue;
        }
        else{
            break;
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
int AcabouJogo(tJogo jogo){
    if(!(TemPosicaoLivreTabuleiro(jogo.tabuleiro))){
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
    char letra = 0;
    printf("Jogar novamente? (s,n)\n");
    scanf("%*[^a-z]");
    
    scanf("%c", &letra);

    if (letra == 's'){
        return 1;
    }
    else if(letra == 'n'){
        return 0;
    }
}
