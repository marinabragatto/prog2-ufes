#include "tarefamultiplica.h"

 struct mult {
    float n1,n2,res;
 };

/**
 * @brief Cria uma tarefa do tipo multiplicação de dois números
 * 
 * @param n1 - Primeiro número que será multiplicado quando a tarefa for executada
 * @param n2 - Segundo número que será multiplicado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tMult* CriaTarefaMultiplicar(float n1, float n2){
    tMult * mult;
    mult = (tMult*)malloc(sizeof(tMult));
    mult->n1 = n1;
    mult->n2 = n2;
    mult->res = -1;
    return mult;
}

/**
 * @brief Função que executa uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaMultiplicar(void *mult){
    ((tMult*)mult)->res = (((tMult*)mult)->n2)*(((tMult*)mult)->n1);
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f",((tMult*)mult)->n1 , ((tMult*)mult)->n2, ((tMult*)mult)->res);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaMultiplicar(void *mult){
    if(mult){
        free(mult);
    }
}