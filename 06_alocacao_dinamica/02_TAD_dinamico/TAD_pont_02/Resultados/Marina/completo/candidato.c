#include "candidato.h"
#include <stdlib.h>


//typedef struct {
  //  char* nome;
  //  char* partido;
    //char cargo;
    //int id;
    //int votos;
//} tCandidato;

/**
 * @brief Cria um candidato "vazio".
 * Os ponteiros devem ser inicializados com NULL e os campos numéricos com o valor -1.
 * @return Candidato criado.
 */
tCandidato* CriaCandidato(){
  tCandidato * canditato;
  canditato = (tCandidato*)malloc(sizeof(tCandidato)*1);

  canditato->partido = NULL;
  canditato->nome = NULL;
  canditato->partido = NULL;
  canditato->id = -1;
  canditato->votos = -1;

  return canditato;

}

/**
 * @brief Apaga toda a memória alocada dinamicamente para guardar as informações de um candidato
 * @param candidato Ponteiro para o candidato que terá a memória desalocada
 * @return Candidato criado.
 */
void ApagaCandidato(tCandidato* candidato){
  if(candidato){
    if(candidato->nome){
      free(candidato->nome);
    }
    else{
      printf("!!tentou liberar ponteiro nome ja nulo!!\n");
      exit(1);
    }
    if(candidato->partido){
      free(candidato->partido);
    }
    else{
      printf("!!tentou liberar ponteiro partido ja nulo!!\n");
      exit(1);
    }
    free(candidato);
  }
  else{
    printf("!!tentou liberar ponteiro candidato ja nulo!!\n");
    exit(1);
  }
        
}

/**
 * @brief Lê um candidato. O número de votos de um candidato deve ser zerado aqui.
 * @param candidato Candidato a ser lido.
 */
void LeCandidato(tCandidato *candidato){
  candidato->nome = (char*)malloc(sizeof(char)*20);
  candidato->partido = (char*)malloc(sizeof(char)*20);
  scanf("%*[^a-zA-Z]");

  scanf("%[^,]", candidato->nome);
  scanf("%*[, ]");
  scanf("%[^,]", candidato->partido);
  scanf("%*[^PG]");
  scanf("%c,", candidato->cargo);
  scanf("%d", candidato->id);

  //Edsger Dijkstra, Partido do Melhor Caminho (PMC), P, 10
}

/**
 * @brief Verifica se o identificador do candidato é igual ao informado.
 * @param candidato Candidato a ser verificado.
 * @param id Identificador a ser comparado.
 * @return 1 se o identificador é igual, 0 caso contrário.
 */
int VerificaIdCandidato(tCandidato *candidato, int id){
  if(candidato->id == id){
    return 1;
  }
  return 0;
}

/**
 * @brief Verifica se dois candidatos são iguais (dica: utilize para verificar se houve empate).
 * @param candidato1 Primeiro candidato a ser comparado.
 * @param candidato2 Segundo candidato a ser comparado.
 * @return 1 se os candidatos são iguais, 0 caso contrário.
 */
int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2){
  if(candidato1->id == candidato2->id){
    return 1;
  }
  return 0;
}

/**
 * @brief Obtém o cargo do candidato.
 * @param candidato Candidato a ser verificado.
 * @return Cargo do candidato.
 */
char ObtemCargo(tCandidato* candidato){
  return candidato->cargo;

}

/**
 * @brief Incrementa 1 voto ao candidato.
 * @param candidato Candidato a ter os votos incrementados.
 */
void IncrementaVotoCandidato(tCandidato* candidato){
  candidato->votos++;
  return;
}

/**
 * @brief Obtém a quantidade de votos do candidato.
 * @param candidato Candidato a ser verificado.
 * @return Quantidade de votos do candidato.
 */
int ObtemVotos(tCandidato* candidato){
  return candidato->votos;
}
/**
 * @brief Calcula o percentual de votos do candidato em relação ao total de votos (do mesmo cargo).
 * @param candidato Candidato a ser verificado.
 * @param totalVotos Total de votos da eleição.
 * @return Percentual de votos do candidato.
 */
float CalculaPercentualVotos(tCandidato* candidato, int totalVotos){
  return (candidato->votos/(float)totalVotos);
}

/**
 * @brief Imprime os dados do candidato na tela.
 * @param candidato Candidato a ser impresso.
 * @param percentualVotos Percentual de votos do candidato.
 */
void ImprimeCandidato (tCandidato* candidato, float percentualVotos){
  float percentual = 12;

  printf("%s (%s), %d voto(s), %.2f%%", candidato->nome, candidato->partido, candidato->votos, percentual);
  return;
}