#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Função que cria uma matriz de inteiros, alocada dinamicamente. Se a alocação falhar, o programa é encerrado.
 * 
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz. 
 * @return Ponteiro para a matriz alocada.
*/
int **CriaMatriz(int linhas, int colunas){
    int **ptrLinhas, i = 0;

    
    ptrLinhas = (int**)malloc(sizeof(int*)*linhas);
    
    for(i = 0; i < linhas; i++){
        ptrLinhas[i] = (int*)malloc((sizeof(int))*colunas);
    }

    return ptrLinhas;
}

/**
 * Função que libera a memória alocada para uma matriz de inteiros.
 * 
 * @param matriz Ponteiro para a matriz a ser liberada.
 * @param linhas Número de linhas da matriz.
*/
void LiberaMatriz(int **matriz, int linhas){
    int i = 0;
    
    if (matriz != NULL){
        for(i = 0; i < linhas; i++){
            if(matriz[i] != NULL){
                free(matriz[i]);
            }
        }
        free(matriz);
    }
    
    
}

/**
 * Função que lê uma matriz de inteiros da entrada padrão.
 * 
 * @param matriz Ponteiro para a matriz a ser lida.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
*/
void LeMatriz(int **matriz, int linhas, int colunas){
    int i = 0, j = 0;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas;j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}
/**
 * Imprime a matriz transposta da matriz dada.
 * 
 * @param matriz Ponteiro para a matriz.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
*/
void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas){
    int i = 0, j = 0;
    for(j = 0; j < colunas; j++){
        for(i = 0; i < linhas;i++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    //LiberaMatriz(matriz, linhas);
}