#include "candidato.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_PAD 10

char *LeString(); 
char *AumentaTamanhoVetor(char* vetor, int *tamanhoantigo);
int EhMultiploDez(int numero);


/**
 * @brief Cria um candidato "vazio".
 * Os ponteiros devem ser inicializados com NULL e os campos numéricos com o valor -1.
 * @return Candidato criado.
 */
tCandidato* CriaCandidato(){
  tCandidato * candidato;
  candidato = (tCandidato*)malloc(sizeof(tCandidato)*1);

  //candidato->nome = (char*)malloc(sizeof(char)*20);
  //candidato->partido = (char*)malloc(sizeof(char)*20);
  
  candidato->partido = NULL;
  candidato->nome = NULL;

  candidato->id = -1;
  candidato->votos = -1;

  return candidato;

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

  candidato->nome = (char*)malloc(sizeof(char)*11);
  candidato->partido = (char*)malloc(sizeof(char)*11);
  //Limpa buffer 
  scanf("%*[^a-zA-Z]");
  //Le uma string (nesse contexto)
  candidato->nome = LeString(candidato->nome);
  //scanf("%39[^,]", candidato->nome);
  //scanf("%*[, ]");
  candidato->partido = LeString(candidato->partido);
  //scanf("%39[^,]", candidato->partido);
  scanf("%*[^PG]");
  scanf("%c, ", &candidato->cargo);
  scanf("%d", &candidato->id);

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
  return candidato->votos+1;
}
/**
 * @brief Calcula o percentual de votos do candidato em relação ao total de votos (do mesmo cargo).
 * @param candidato Candidato a ser verificado.
 * @param totalVotos Total de votos da eleição.
 * @return Percentual de votos do candidato.
 */
float CalculaPercentualVotos(tCandidato* candidato, int totalVotos){
  return (ObtemVotos(candidato)/(float)totalVotos);
}

/**
 * @brief Imprime os dados do candidato na tela.
 * @param candidato Candidato a ser impresso.
 * @param percentualVotos Percentual de votos do candidato.
 */
void ImprimeCandidato (tCandidato* candidato, float percentualVotos){

  percentualVotos = percentualVotos*100;

  printf("%s (%s), %d voto(s), %.2f%%\n", candidato->nome, candidato->partido, ObtemVotos(candidato), percentualVotos);
  return;
}

char *LeString(char *string){
    int i = 0;
    char letra = 'a';
    int *tamanho;
    int tam = TAM_PAD;
    *tamanho = tam;

    for(i = 0; 1; i++){
        scanf("%c", &letra);
        if(letra != ','){
            if(EhMultiploDez(i)){
                string = AumentaTamanhoVetor(string, tamanho);
                *tamanho += 10; 
            }
            string[i] = letra;
        }
        else {
            break;
        }
    }
    return string;
}

char *AumentaTamanhoVetor(char* vetor, int *tamanhoantigo){
    vetor = (char*)realloc(vetor, sizeof(char)*(*(tamanhoantigo)+11));
    *(tamanhoantigo)++;
    return vetor;
}

int EhMultiploDez(int numero){
    if(((numero%10) == 0) && numero != 0){
        return 1;
    }
    else {
        return 0;
    }
}