#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrizgenerica.h"

struct matrizgenerica {
    int lin;
    int col;
    void *** data;
    int novoNumByteElem;

};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar uma Matriz de qualquer tipo de dados,
 * desde que esse tipo ocupe determinado número de bytes.
 *
 * @param linhas - Numero de linhas da matriz
 * @param colunas - Numero de colunas da matriz
 * @param numByteElem - Número de Bytes que cada elemento da matriz ocupará
 *
 * @return Um ponteiro para a estrutura que armazena uma matriz genérica
 */
tMatrizGenerica * CriaMatrizGenerica(int linhas, int colunas, int numByteElem){
    tMatrizGenerica * mat;
    //printf("%d %d %d", linhas, colunas, numByteElem);

    mat = (tMatrizGenerica*)malloc(sizeof(tMatrizGenerica));
    
    mat->col = colunas;
    mat->lin = linhas;
    mat->novoNumByteElem = numByteElem;
    
    mat->data = (void***)malloc(sizeof(void**)*linhas);
    
    int i = 0;
    for(i = 0; i < linhas; i++){
        mat->data[i] = (void**)malloc(sizeof(void*)*colunas);
    }

    int j = 0;
    for(i = 0; i < linhas; i++){
        for(j = 0 ; j < colunas; j++){
            mat->data[i][j] = NULL;
            //mat->data[i][j] = (void*)malloc(numByteElem);
        }
    }

    return mat;
}

/**
 * @brief Libera a memória alocada dinamicamente para uma matriz
 *
 * @param mat - Ponteiro para a matriz a ser liberada
 *
 */
void DestroiMatrizGenerica(tMatrizGenerica * mat){
    
    if(mat){
        int j = 0, i = 0;
        if(mat->data){
            for(i = 0; i < mat->lin; i++){
                if(mat->data[i]){
                    for(j = 0 ; j < mat->col;j++){
                        if(mat->data[i][j]){
                            free(mat->data[i][j]);
                        }
                    }
                    free(mat->data[i]);
                }
            }
            free(mat->data);
        }
        free(mat);
    }

}
/**
 * @brief Obtém o número de linhas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de linhas
 *
 * @return O número de linhas da matriz
 */
int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica * mat){
    return mat->lin;
}

/**
 * @brief Obtém o número de colunas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de colunas
 *
 * @return O número de colunas da matriz
 */
int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica * mat){
    return mat->col;
}

/**
 * @brief Obtém ponteiro para um elemento qualquer da matriz genérica.
 *
 * @param mat - Ponteiro para a matriz que queremos encontrar o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento está
 * @param coluna - Coluna que o elemento está
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void * ObtemElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna){

    return mat->data[linha][coluna];
}

/**
 * @brief Atribui um elemento a uma posição de uma matriz.
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento ficará
 * @param coluna - Coluna que o elemento ficará
 * @param *elem - Ponteiro para o elemento que será colocado na matriz (será feita uma cópia)
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void AtribuiElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna, void* elem){
    if(mat->data[linha][coluna] != NULL){
        free(mat->data[linha][coluna]);
    }
    
    mat->data[linha][coluna] = (void*)malloc(mat->novoNumByteElem);
    memcpy(mat->data[linha][coluna], elem, mat->novoNumByteElem);
    //*(mat->data[linha][coluna]) = *elem;
}

/**
 * @brief Imprime os elementos usando um callback para imprimir o tipo de dados da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param imprime_elemento - Ponteiro para a função (callback) que tem a capacidade de imprimir os dados de um elemento desta matriz
 */

void ImprimirMatrizGenerica(tMatrizGenerica * mat, void (imprime_elemento(void*))){
    int i = 0, j = 0;


    for(i = 0 ; i < mat->lin; i++){
        for(j = 0; j < mat->col; j++){
            imprime_elemento(mat->data[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

/**
 * @brief Encontra a transposta de uma matriz passada como parâmetro
 *
 * @param mat - A matriz que queremos encontrar a transposta
 *
 * @return Ponteiro para uma nova matriz, igual à transposta da matriz mat
 */
tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat){
    tMatrizGenerica * res;
    
    res = CriaMatrizGenerica(mat->col, mat->lin, mat->novoNumByteElem);
    
    int i = 0, j = 0;

    for(i = 0; i < mat->col; i++){
        for(j = 0; j < mat->lin; j++){
            //free(res->data[i][j]);
            AtribuiElementoMatrizGenerica(res, i, j, mat->data[j][i]);
        }
    }
    return res;
}

/**
 * @brief Calcula e retorna a multiplicação entre duas matrizes
 *
 * @param mat1 - A primeira matriz da multiplicação
 * @param mat2 - A segunda matriz da multiplicação
 * @param numByteTarget - Número de bytes do elemento resultante 
 * @param multi_elem - Ponteiro para função (callback) que realiza a multiplicação entre dois elementos do tipo de dados contido na matriz
 * @param soma_elem - Ponteiro para função (callback) que realiza a soma entre dois elementos do tipo de dados contido na matriz
 *
 * @return Ponteiro para uma nova matriz, igual a multiplicação entre mat1 e mat2.
 */
tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void* (*multi_elem)(void*, void*), void* (*soma_elem)(void*,void*)){
    tMatrizGenerica * res;
    res = CriaMatrizGenerica(mat1->lin, mat2->col, mat1->novoNumByteElem);
    int i = 0, j = 0, m = 0;
    int ord = mat1->col;
    void * mult, *soma  ;

    for(i = 0; i < res->lin; i++){
        for(j = 0; j < res->col; j++){
            for(m = 0; m <  ord; m++){

                mult = multi_elem(mat1->data[i][m], mat2->data[m][j]);
                
                if(m == 0){
                    AtribuiElementoMatrizGenerica(res,i,j,  mult);
                }
                else{
                    soma = soma_elem(res->data[i][j], mult);
                    AtribuiElementoMatrizGenerica(res,i,j, soma); 
                    free(soma);
                }  
                  
                free(mult);
            }
        }
    }
    return res;
}


/**
 * @brief Converte o tipo da matriz
 *
 * @param mat - A matriz que queremos converter para o novo tipo
 * @param novoNumByteElem - Número de bytes do novo tipo da matriz
 * @param converte_elem - Ponteiro para função que tem a capacidade de converter o elemento do tipo original para o novo tipo
 *
 * @return Ponteiro para uma nova matriz, no novo formato
 */
tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void* (*converte_elem)(void*)){
    tMatrizGenerica * mat3;

    void * novo;
    mat3 = CriaMatrizGenerica(mat2->lin, mat2->col, novoNumByteElem);

    int j = 0, i = 0;
    for(i = 0; i < mat2->lin; i++){
        for(j = 0 ; j < mat2->col; j++){
    
            novo = converte_elem(mat2->data[i][j]);
            AtribuiElementoMatrizGenerica(mat3,i,j, novo);
            free(novo);
            
        }
    }

    return mat3;
}