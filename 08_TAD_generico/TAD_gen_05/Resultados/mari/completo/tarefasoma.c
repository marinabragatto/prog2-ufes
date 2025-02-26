#include "tarefasoma.h"

struct soma {
    float n1;
    float n2;
    float res;

};

/**
 * @brief Cria uma tarefa do tipo soma de dois números
 * 
 * @param n1 - Primeiro número que será somado quando a tarefa for executada
 * @param n2 - Segundo número que será somado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tSoma* CriaTarefaSoma(float n1, float n2){
    tSoma * soma;
    soma = (tSoma*)malloc(sizeof(tSoma));
    soma->n1 = n1;
    soma->n2 = n2;
    soma->res = -1;
    return soma;
}

/**
 * @brief Função que executa uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaSoma(void *sum){
    //tSoma * soma = ((tSoma*)sum);
    ((tSoma*)sum)->res = ((tSoma*)sum)->n2 + ((tSoma*)sum)->n1 ;
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f",((tSoma*)sum)->n1, ((tSoma*)sum)->n2, ((tSoma*)sum)->res);
    //O resultado da soma de 1.00 com 1.00 eh: 2.00
    //return sum;
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaSoma(void *sum){
    if(sum){
        free(sum);
    }
}