#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Cria um vetor de inteiros de tamanho especificado, alocado dinamicamente.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @param tamanho Tamanho do vetor a ser criado.
 * @return Ponteiro para o vetor criado.
 */
int *CriaVetor(int tamanho){
    int *ptr;
    ptr = malloc(sizeof(int)*tamanho);
    return ptr;
}

/**
 * Lê um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
*/
void LeVetor(int *vetor, int tamanho){
    int i = 0;
    
    for(i = 0; i < tamanho;i++){
        scanf("%d", &vetor[i]);
    }

    return;
}

/**
 * Calcula a média dos valores de um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
*/
float CalculaMedia(int *vetor, int tamanho){
    int i = 0;
    float soma = 0;
    
    for(i = 0; i < tamanho;i++){
        soma += vetor[i];
    }

    return (soma/tamanho);
}

/**
 * Libera a memória alocada para um vetor de inteiros.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(int *vetor){
    if(vetor != NULL){
        free(vetor);
    }
    else {
        printf("!!!tentou liberar vetor nulo!!!\n");
        exit(-1);
    }
    
}