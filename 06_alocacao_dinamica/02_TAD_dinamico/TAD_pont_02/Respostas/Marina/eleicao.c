#include "eleicao.h"
#include <stdlib.h>
#include <stdio.h>

int candidatoVotado(tCandidato ** candidatos, int qtdCandidatos, int idBuscado);
int EleitorTentouVotarDnv(tEleitor ** eleitores, int qtdEleitores);
int Vencedor(tCandidato ** candidatos, int total);

// #define MAX_CANDIDATOS_POR_CARGO 3
// #define MAX_ELEITORES 10

/*typedef struct {
    tCandidato** presidentes;
    int totalPresidentes;

    tCandidato** governadores;
    int totalGovernadores;

    int votosBrancosPresidente;
    int votosNulosPresidente;

    int votosBrancosGovernador;
    int votosNulosGovernador;

    tEleitor** eleitores;
    int totalEleitores;
    
} tEleicao;*/

/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao* InicializaEleicao(){
    tEleicao *eleicao;
    float k = 0; int z = 1;
    eleicao = (tEleicao*)malloc(sizeof(tEleicao));
    int qtdCandidatos = 0, i = 0;

    //inicia votos
    eleicao->votosNulosPresidente = 0;
    eleicao->votosNulosGovernador = 0;
    eleicao->votosBrancosPresidente = 0;
    eleicao->votosBrancosGovernador = 0;
    //inicia totais
    eleicao->totalEleitores = 0;
    eleicao->totalGovernadores = 0;
    eleicao->totalPresidentes = 0;

    eleicao->eleitores = NULL;
    
  
    
    scanf("%d", &qtdCandidatos);

    
    eleicao->presidentes = (tCandidato**)malloc(sizeof(tCandidato*)*qtdCandidatos);
    for(i = 0; i < qtdCandidatos; i++){
        eleicao->presidentes[i] = CriaCandidato();
    }

    
    eleicao->governadores = (tCandidato**)malloc(sizeof(tCandidato*)*qtdCandidatos);
    for(i = 0; i < qtdCandidatos; i++){
        eleicao->governadores[i] = CriaCandidato();
    }

    int idxPresidente = 0, idxGovernador = 0;

    tCandidato *candidatoAtual;
    candidatoAtual = CriaCandidato();

    for(i = 0; i < qtdCandidatos; i++){
        LeCandidato(candidatoAtual);
        if(ObtemCargo(candidatoAtual) == 'P'){
            *(eleicao->presidentes[eleicao->totalPresidentes]) = *(candidatoAtual);
            eleicao->totalPresidentes++;
        }
        else if(ObtemCargo(candidatoAtual) == 'G'){
            *(eleicao->governadores[eleicao->totalGovernadores]) = *(candidatoAtual);
            eleicao->totalGovernadores++;
        }    
    }
    if(candidatoAtual){
        free(candidatoAtual);
    }

//    for(i  = 0; i < eleicao->totalGovernadores; i++){
//        printf("!!governadores!!\n");
//       ImprimeCandidato(eleicao->governadores[i], 100);
//    }
//    for(i  = 0; i < eleicao->totalPresidentes; i++){
//        printf("!!presidentes!!\n");
//        ImprimeCandidato(eleicao->presidentes[i], 100);
//    }

    return eleicao;

}


void ApagaEleicao(tEleicao* eleicao){
    int i = 0;
    int qtdTotal = 0;
    qtdTotal = eleicao->totalPresidentes + eleicao->totalGovernadores;
    
    if(eleicao){
        for(i = 0; i < qtdTotal; i++){
            ApagaCandidato(eleicao->presidentes[i]);
            ApagaCandidato(eleicao->governadores[i]);
        }
        free(eleicao->presidentes);
        free(eleicao->governadores);

        for(i = 0; i < eleicao->totalEleitores; i++){
            ApagaEleitor(eleicao->eleitores[i]);
        }
    
        free(eleicao->eleitores);
        free(eleicao);
    }
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada. 
 */
void RealizaEleicao(tEleicao* eleicao){
    int i = 0;
    int qtdEleitores = 0;
    scanf("%d", &qtdEleitores);

    //eleicao->totalEleitores
    eleicao->eleitores = (tEleitor**)malloc(sizeof(tEleitor)*qtdEleitores);
    for(i = 0; i < qtdEleitores;i++){
        eleicao->eleitores[i] = CriaEleitor();
    }

    //tEleitor eleitorAtual();
    for(i = 0; i < qtdEleitores; i++){
        LeEleitor(eleicao->eleitores[i]);
    }
    eleicao->totalEleitores = qtdEleitores;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao* eleicao){
    int i = 0, votoPatual = 0, votoGatual = 0;
    int idxPresidente = 0, idxGovernador = 0;

    if(EleitorTentouVotarDnv(eleicao->eleitores, eleicao->totalEleitores)){
        printf("ELEICAO ANULADA\n");
    } else {

        for(i = 0; i < eleicao->totalEleitores; i++){
            votoPatual  = ObtemVotoPresidente(eleicao->eleitores[i]);
            votoGatual = ObtemVotoGovernador(eleicao->eleitores[i]);
            if(votoGatual == 0){
                eleicao->votosBrancosGovernador++;
            }
            else{
                idxGovernador = candidatoVotado(eleicao->governadores, eleicao->totalGovernadores, votoGatual);
                if(idxGovernador != -1){
                    IncrementaVotoCandidato(eleicao->governadores[idxGovernador]);
                }
                else{
                    eleicao->votosNulosGovernador++;
                }

            }

            if(votoPatual == 0){
                eleicao->votosBrancosPresidente++;
            }
            else{
                idxPresidente = candidatoVotado(eleicao->presidentes, eleicao->totalPresidentes, votoPatual);
                if(idxPresidente != -1){
                    IncrementaVotoCandidato(eleicao->presidentes[idxPresidente]);
                }
                else{
                    eleicao->votosNulosPresidente++;
                }
            }
        }
    
        idxPresidente = Vencedor(eleicao->presidentes, eleicao->totalPresidentes);
        idxGovernador = Vencedor(eleicao->governadores, eleicao->totalGovernadores);


        int totalVotosPresidentes = eleicao->totalEleitores;
        int totalVotosGovernadores =  eleicao->totalEleitores ;

        int nulos = eleicao->votosNulosGovernador + eleicao->votosNulosPresidente;
        int brancos = eleicao->votosBrancosPresidente + eleicao->votosBrancosGovernador;
        
        printf("- PRESIDENTE ELEITO: ");
        if(idxPresidente != -1){
            if(ObtemVotos(eleicao->presidentes[idxPresidente]) < (eleicao->votosBrancosPresidente + eleicao->votosNulosPresidente)){
                printf("SEM DECISAO\n");
            }
            else{
                ImprimeCandidato(eleicao->presidentes[idxPresidente], CalculaPercentualVotos(eleicao->presidentes[idxPresidente], totalVotosPresidentes));
            }
            
        }
        else{
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }
        
        printf("- GOVERNADOR ELEITO: ");
        if(idxGovernador != -1){
            if(ObtemVotos(eleicao->governadores[idxGovernador]) < (eleicao->votosNulosGovernador + eleicao->votosBrancosGovernador)){
                printf("SEM DECISAO\n");
            }
            else {
                ImprimeCandidato(eleicao->governadores[idxGovernador], CalculaPercentualVotos(eleicao->governadores[idxGovernador], totalVotosGovernadores));
            }
            
        }
        else {
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }
        
        printf("- NULOS E BRANCOS: %d, %d\n", nulos, brancos);        
            
    }

}
    


int candidatoVotado(tCandidato ** candidatos, int qtdCandidatos, int idBuscado){
    int i = 0;
    for(i = 0 ; i < qtdCandidatos; i++){
        if(VerificaIdCandidato(candidatos[i], idBuscado)){
            return i;
        }
    }
    return -1;
}

int EleitorTentouVotarDnv(tEleitor ** eleitores, int qtdEleitores){
    int i = 0, j = 0;

    for(i = 0; i < qtdEleitores; i++){
        for(j = 0; j < qtdEleitores;j++){
            if(EhMesmoEleitor(eleitores[i], eleitores[j]) && j != i){
                return 1;
            }
        }
    }
    return 0;
}

int Vencedor(tCandidato ** candidatos, int total){
    int i = 0; 
    int maior = 0, idxMaior = 0;
    maior = candidatos[0]->votos;
    idxMaior = 0;
    
    for(i = 1 ; i < total; i++){
        if(candidatos[i]->votos > maior){
            maior = candidatos[i]->votos;
            idxMaior = i;
        }
    }

    for(i = 0; i < total;i++){
        if(candidatos[i]->votos == maior){
            if(i != idxMaior){
                return -1;
            }
        }
    }

    return idxMaior;
}