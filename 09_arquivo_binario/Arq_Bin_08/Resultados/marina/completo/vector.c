#include "vector.h"
#include <stdlib.h>

//typedef void *DataType; // void pointer
struct Vector {
    DataType * data;
    DataType * lixos;
    int tamLixo;
    int tamAtual, tamMax;
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
    vector->lixos = NULL;
    vector->tamAtual = 0;
    vector->tamMax = 0;
    vector->tamLixo = 0;

    return  vector;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    if(v->tamMax <= v->tamAtual){
        v->data = (DataType*)realloc(v->data,sizeof(DataType)*(v->tamAtual+1));
        v->tamMax++;
    }
    v->data[v->tamAtual] = val;
    v->tamAtual++;
}

/**
 * @brief Remove o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
*/
void VectorRemove(Vector *v, int i){

    v->lixos = (DataType*)realloc(v->lixos,sizeof(DataType)*(v->tamLixo+1));
    v->lixos[v->tamLixo] = v->data[i];
    v->tamLixo++;
    
    v->tamAtual--;
    int j;
    for(j = i; j < v->tamAtual; j++){
        v->data[j] = v->data[j+1];
    }
    v->data[j] = NULL;
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
        if(v->lixos){
            for(int i = 0; i < v->tamLixo; i++){
                if(v->lixos[i]){
                   // destroy(v->lixos[i]);
                    v->lixos[i]=NULL;
                }
            }
            free(v->lixos);
        }
        if(v->data){
            for(int i = 0; i < v->tamAtual; i++){
                if(v->data[i]){
                    destroy(v->data[i]);
                   v->data[i]=NULL;
                }
            }
            free(v->data);
        } 
        
        free(v);
    }
}