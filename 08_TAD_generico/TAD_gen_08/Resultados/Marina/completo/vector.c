#include "vector.h"
#include <stdlib.h>

//typedef void *DataType; // void pointer
struct Vector {
    int tamanhoAtual;
    int tamMax;
    DataType * dados;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector * vec;
    vec = (Vector*)malloc(sizeof(Vector));
    vec->dados = NULL;
    vec->tamMax = 0;
    vec->tamanhoAtual = 0;

    return vec;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    v->dados = (DataType*)realloc(v->dados, sizeof(DataType)*(v->tamanhoAtual+1));
    v->dados[v->tamanhoAtual] = val;
    v->tamanhoAtual++;
    v->tamMax++;
}

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou seja, 
 * o segundo elemento passa a ser o primeiro, o terceiro passa a ser o segundo, e assim por diante.
 * 
 * @param v Ponteiro para o vetor
 * @return DataType Elemento removido
*/
DataType VectorPopFront(Vector *v){
    DataType aux;
    DataType rem;

    rem = v->dados[0];

    int tamMax = v->tamMax;
    aux = v->dados[v->tamMax-1];

    v->dados[v->tamMax-1] = v->dados[0];

    int i = 0;
    for(i = 0; i < tamMax-2; i++){
        v->dados[i] = v->dados[i+1];
    }
    v->dados[i] = aux;
    v->tamanhoAtual--;
    
    return rem;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){
    return v->dados[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){
    return v->tamanhoAtual;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    if(v){
        if(v->dados){
            int i  = 0;
            for(i = 0; i < v->tamanhoAtual; i++){
                destroy(v->dados[i]);
            }
            free(v->dados);
        }
        free(v);
    }
}