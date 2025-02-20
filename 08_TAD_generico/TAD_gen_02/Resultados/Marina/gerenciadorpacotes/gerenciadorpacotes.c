#include "gerenciadorpacotes.h"
#include <stdlib.h>

#define TAM_MIN 10

struct gerenciadorpacotes {
    tPacote **pacotes;
    int qtdMax;
    int qtdAtual;
};

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador(){
    tGerenciador * gerencia;
    gerencia = (tGerenciador*)malloc(sizeof(tGerenciador));
    
    gerencia->qtdAtual = 0;
    gerencia->qtdMax = TAM_MIN;

    gerencia->pacotes = (tPacote**)malloc(sizeof(tPacote*)*TAM_MIN);
    
    return gerencia;

}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){
    if(geren->qtdAtual >= geren->qtdMax){
        geren->pacotes = realloc(geren->pacotes, sizeof(tPacote*)*(TAM_MIN+geren->qtdAtual));
        geren->qtdMax += TAM_MIN;
    }
    geren->pacotes[geren->qtdAtual] = pac;
    geren->qtdAtual++;
    return;
}

/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren){
    if(geren){
        if(geren->pacotes){
            int i = 0; 
            for(i = 0; i < geren->qtdAtual; i++){
                if(geren->pacotes[i]){
                    DestroiPacote(geren->pacotes[i]);
                }
            }
            free(geren->pacotes);
        }

        free(geren);
    }
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){
    int i = 0;

    for(i = 0; i < geren->qtdAtual; i++){
        if(i == idx){
            ImprimePacote(geren->pacotes[i]);
        }
       
    }
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren){
    int i = 0;

    for(i = 0; i < geren->qtdAtual; i++){
        ImprimePacote(geren->pacotes[i]);
    }
}

