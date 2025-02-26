#include "agendatarefas.h"
#include <stdlib.h>

typedef struct {
    void (*executa)(void*);
    void (*destroi)(void*);
    void * tarefaType;
    int prioridade;
}tTarefaUtils;



struct agendatarefas {
    //void **tarefas;
    int tamanho;
    int qtdAtual;
    tTarefaUtils ** tarefas; 
    //void (**executa)(void*);
    //void (**destroi)(void*);

};

tTarefaUtils * criaTarefa(int prioridade, void * tarefa, void (*executa)(void*), void (*destroi)(void*));
void ExecutaTafUtils(tTarefaUtils * tafUtils);
void LiberaTarefaUtils(tTarefaUtils * tafUtils);
void ordenaTafUtils(tTarefaUtils ** tarefasVector, int qtdAtual);
int comparaDuasTarefas(tTarefaUtils * vector, tTarefaUtils * maior);


/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem){
    tAgendaTarefas * agenda;
    agenda = (tAgendaTarefas*)malloc(sizeof(tAgendaTarefas));
    agenda->tarefas = (tTarefaUtils**)malloc(sizeof(tTarefaUtils*)*numElem);

    int i = 0;
    for(i = 0; i < numElem; i++){
        agenda->tarefas[i] = NULL;
    }
    
    //agenda->tarefas = (void**)malloc(sizeof(void*)*numElem);
    agenda->tamanho = numElem;
    agenda->qtdAtual = 0;
    return agenda;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar){
    if(tar){
        if(tar->tarefas){
            int i = 0;
            for(i = 0; i < tar->qtdAtual; i++){
                //LiberaTarefaUtils(tar->tarefas[i]);
            }
            free(tar->tarefas);
        }
        free(tar);
    }
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){
    tTarefaUtils * taf;

    taf = criaTarefa(prioridade, tarefa, executa, destroi);

    tar->tarefas[tar->qtdAtual] = taf;

    tar->qtdAtual++;
    return;

}

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){

    int i = 0, j= 0;
    
    int idxMaior = 0;
    tTarefaUtils * tarefaMaior = tar->tarefas[0];
    int achou = 0;
    int k = 0;

    for(i = 0; i < tar->qtdAtual  ; i++){
        achou = 0;
        for(k = 0; k < tar->qtdAtual; k++){
            if(tar->tarefas[k] != NULL){
                idxMaior = k;
                tarefaMaior = tar->tarefas[k];
                break;
            }
            else{
                achou++;
            }
        }
        if(achou == tar->qtdAtual - 1){
            break;
        }
        

        for(j = 0 ; j < tar->qtdAtual; j++){
            if(tar->tarefas[j] != NULL){
                if(comparaDuasTarefas(tar->tarefas[j], tarefaMaior)){
                    idxMaior = j;
                    tarefaMaior = tar->tarefas[j];
                }
            }
            
        }

        if(tar->tarefas[idxMaior] != NULL){
            ExecutaTafUtils(tar->tarefas[idxMaior]);
            LiberaTarefaUtils(tar->tarefas[idxMaior]);

            tar->tarefas[idxMaior] = NULL;
        }

    }


}

tTarefaUtils * criaTarefa(int prioridade, void * tarefa, void (*executa)(void*), void (*destroi)(void*)){
    tTarefaUtils * taf;
    taf = (tTarefaUtils*)malloc(sizeof(tTarefaUtils));
    
    taf->prioridade = prioridade;
    taf->destroi = destroi;
    taf->executa = executa;
    taf->tarefaType = tarefa;
    
    return taf;
}
void ExecutaTafUtils(tTarefaUtils * tafUtils){
    tafUtils->executa(tafUtils->tarefaType);
}
void LiberaTarefaUtils(tTarefaUtils * tafUtils){
    if(tafUtils){
        if(tafUtils->tarefaType){
            tafUtils->destroi(tafUtils->tarefaType);
        }
      //  tafUtils.
        free(tafUtils);
    }
}

void ordenaTafUtils(tTarefaUtils ** tarefasVector, int qtdAtual){
    int i = 0, j= 0;
    
    int idxMaior = 0;
    tTarefaUtils * tarefaMaior = tarefasVector[0];

    for(i = 0; i < qtdAtual - 1; i++){
        idxMaior = i;
        tarefaMaior = tarefasVector[i];

        for(j = i+1 ; j < qtdAtual; j++){
            if(comparaDuasTarefas(tarefasVector[j], tarefaMaior)){
                idxMaior = j;
                tarefaMaior = tarefasVector[j];
            }
        }

        if(tarefasVector[i]->prioridade <= tarefaMaior->prioridade){
            tTarefaUtils * aux;
            aux = tarefasVector[i];
            tarefasVector[i] = tarefasVector[idxMaior];
            tarefasVector[idxMaior] = aux;
        }
    }
}

int comparaDuasTarefas(tTarefaUtils * vector, tTarefaUtils * maior){
    if(vector->prioridade > maior->prioridade){
        return 1;
    }
    else {
        return 0;
    }
}