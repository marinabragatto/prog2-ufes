#include "array.h"
#include <stdlib.h>
#include <stdio.h>

int * AumentaTamanhoArray(int * data, int * tamanho);

//typedef struct Array {
//   int *data;
 //  int tamanho;
//} Array;

/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja possível alocar memória.
 */
Array *CriarArray(){
    Array *array;
    array = (Array*)malloc(sizeof(Array));
    array->data = NULL;
    array->tamanho = 0;
    return array;
}

/**
 * @brief Libera a memória alocada para o array.
 * @param array Ponteiro para a estrutura Array a ser destruída.
 */
void DestruirArray(Array *array){
    if(array){
        if(array->data){
            free(array->data);
        }
        free(array);
    }
        
}

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória para eles.
 * @details A leitura é feita até encontrar um ponto final (.) na entrada.
 * @param array Ponteiro para a estrutura Array a ser preenchida.
 */
void LerArray(Array *array){
    char lixo = 'a';
    int numero = 0;
    int idx = 0;

    while(1){
        scanf("%d%c", &numero, &lixo);
        if(1){
            array->data = AumentaTamanhoArray(array->data, &array->tamanho);
        }
        array->data[idx] = numero;
        idx++;
        if(lixo == '.'){
            break;
        }
    }
}

/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array){
    int idxMenor = 0, menor = 0, i = 0, j = 0;
    

 //   printf("antes:::!!!\n");
    for(i = 0; i < array->tamanho;i++){
     //   printf("%d ", array->data[i]);
    }
   // printf("\n\n");
    for(i= 0; i < array->tamanho-1;i++){
        idxMenor = i;
        menor = array->data[i];
        for(j = i+1 ; j < array->tamanho;j++){
            if(menor > array->data[j]){
                idxMenor = j;
                menor = array->data[j];
            }
        }
        if(menor < array->data[i]){
            int aux;
            aux = array->data[idxMenor];
            array->data[idxMenor] = array->data[i];
            array->data[i] = aux;
        }
    }
   // printf("depois:::!!!\n");
    for(i = 0; i < array->tamanho;i++){
     //   printf("%d ", array->data[i]);
    }
   // printf("\n");
}

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * @param array Ponteiro para a estrutura Array a ser buscada.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado){
    int inicio = 0, fim = array->tamanho - 1;
    
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2; // Cálculo correto do meio

        if (array->data[meio] == elementoBuscado) {
            return meio; // Encontrado
        }

        if (array->data[meio] > elementoBuscado) {
            fim = meio - 1; // Busca na metade esquerda
        } else {
            inicio = meio + 1; // Busca na metade direita
        }
    }
    return -1; // Elemento não encontrado

   
}

int * AumentaTamanhoArray(int * data, int * tamanho){
    data = (int*)realloc(data, sizeof(int)*((*tamanho)+1));
    (*tamanho)++;
    return data;
}

/*if (restoBusca == 0){
                int tamanho = 0;

                tamanho = (idxAnterior - idxBusca) -1;
                idxAnterior = idxBusca;
                idxBusca = tamanho/2 + idxBusca + 1;

            }
            else if(restoBusca != 0){
                int tamanho = 0;
                tamanho = idxAnterior - idxBusca;
                idxAnterior = idxBusca;
                idxBusca = tamanho/2 + 1 + idxBusca;
            }*/


           /*
           while(1){
           if(inicio >= fim){
            break;
            }
        if(array->data[meio] == elementoBuscado){
            return meio;
        }
        

        if(array->data[meio] >= elementoBuscado){
            inicio = inicio;
            fim = meio - 1;
            meio = inicio + (fim - inicio + 1)/2;
        }
        else if(array->data[meio] <= elementoBuscado){ 
            inicio = meio+1;
            fim = fim;
            meio = inicio + (fim - inicio + 1)/2;
        }

    }
    return -1;
           */

/*
    int inicio = 0, fim = array->tamanho - 1;
    int meio = (fim - inicio + 1)/2;



    while(1){
    if(inicio >= fim){
            break;
        }
        if(array->data[meio] == elementoBuscado){
            return meio;
        }
        

        if(array->data[meio] >= elementoBuscado){
            inicio = inicio;
            fim = meio - 1;
            meio = inicio + (fim - inicio + 1)/2;
        }
        else if(array->data[meio] <= elementoBuscado){ 
            inicio = meio+1;
            fim = fim;
            meio = inicio + (fim - inicio + 1)/2;
        }

    }
    return -1;



*/          