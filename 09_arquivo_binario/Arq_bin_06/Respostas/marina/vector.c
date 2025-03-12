#include "vector.h"
#include <stdlib.h>
#include <stdio.h>


struct Vector {
    DataType * data;
    int tamAtual;
    int tamMax;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector * vector;
    vector = (Vector*)malloc(sizeof(Vector));
    vector->data = NULL;
    vector->tamAtual = 0;
    vector->tamMax = 0;
    return vector;

}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    if(v->tamMax<= v->tamAtual){
        v->data = (DataType *)realloc(v->data, sizeof(DataType)*(v->tamMax+1));
        v->tamMax++;
    }
    v->data[v->tamAtual] = val;
    v->tamAtual++;

}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){
    return v->data[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){
    return v->tamAtual;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    if(v){
        if(v->data){
            for(int i = 0; i < v->tamAtual; i++){
                if(v->data[i]){
                    destroy(v->data[i]);
                }
            }
            free(v->data);
        }
            
        free(v);
    }
}