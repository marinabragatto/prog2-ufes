#include "vetor.h"


/**
 * Lê um vetor da entrada padrão.
 * 
 * @param vetor Ponteiro para o vetor que será lido.
 */
void LeVetor(Vetor *vetor){
    int qtd = 0, i = 0;

    scanf("%d", &vetor->tamanhoUtilizado);
    for(i = 0; i < vetor->tamanhoUtilizado; i++){
        scanf("%d", &vetor->elementos[i]);
        //printf("%d ", vetor->elementos[i]);
    }
}

/**
 * Aplica uma operação em um vetor.
 * 
 * @param vetor Ponteiro para o vetor que será utilizado.
 * @param op Ponteiro para a função que será aplicada.
 * @return O resultado da operação.
*/
int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int i = 0, soma = 0, acumulador = 0;

    acumulador = vetor->elementos[i];

    for(i = 0; i < vetor->tamanhoUtilizado-1; i++){
        acumulador = op(acumulador, (vetor->elementos[i+1]));
    }
    return acumulador;
}