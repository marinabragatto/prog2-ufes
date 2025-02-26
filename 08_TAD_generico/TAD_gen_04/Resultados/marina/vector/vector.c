#include "vector.h"
#include <stdlib.h>

//typedef void *DataType; // void pointer
 struct Vector {
    int tamanho;
    DataType * vector;
 };

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector * vector;
    
    vector = (Vector*)malloc(sizeof(Vector));
    vector->vector = NULL;
    vector->tamanho = 0;

    return vector;
}


/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    v->vector = (DataType*)realloc(v->vector, sizeof(DataType)*(v->tamanho + 1));
    v->vector[v->tamanho] = val;
    v->tamanho++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){
    return v->vector[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){
    return v->tamanho;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    if(v){
        if(v->vector){
            int i = 0;
            for(i = 0; i < VectorSize(v); i++){
                destroy(v->vector[i]);
            }
            free(v->vector);
        }
        free(v);
    }
}