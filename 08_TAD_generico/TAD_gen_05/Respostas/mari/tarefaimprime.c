#include "tarefaimprime.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct impr {
    char * msg;
};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg){
    tImpr * imp;
    imp = (tImpr*)malloc(sizeof(tImpr));
    int tam = strlen(msg);

    imp->msg = (char*)malloc(sizeof(char)*(tam+1));
    strcpy(imp->msg, msg);

    return imp;
}
/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp){
    printf("\n%s", ((tImpr*)imp)->msg);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp){
    if(imp){
        if(((tImpr*)imp)->msg){

            free(((tImpr*)imp)->msg);
        }
        free(imp);
    }
}