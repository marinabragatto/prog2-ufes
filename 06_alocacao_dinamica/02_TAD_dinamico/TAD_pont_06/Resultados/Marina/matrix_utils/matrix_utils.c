#include "matrix_utils.h"

//#define MAX_MATRIX_SIZE 10

//typedef struct Matrix{
//    int rows;
//    int cols;
//    int **data;
//} tMatrix;

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado. Alocar dinamicamente o espaço na memória para a matriz bidimensional
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix* MatrixCreate(int rows, int cols){
    tMatrix *matrix;
    int i = 0;

    matrix = (tMatrix*)malloc(sizeof(tMatrix));
    
    if(!matrix){
        printf("nao conseguiu alocar espaco para matriz!\n");
        exit(1);
    }
    //printf("\n((%d %d))\n", rows, cols);
    matrix->cols = cols;
    matrix->rows = rows;

    matrix->data = (int**)malloc(sizeof(int*)*rows);
    
    if(!matrix->data){
        printf("nao conseguiu alocar espaco para a data da matriz!");
        exit(1);
    }
    
    for(i = 0; i < rows; i++){

        matrix->data[i] = (int*)malloc((sizeof(int))*cols);
        
        if(!matrix->data[i]){
            printf("nao conseguiu alocar espaco para a data rows da matriz!\n");
            exit(1);
        }
    }

    return matrix;
}

/**
 * @brief Libera toda a memória alocada por uma matriz
 * @param matrix O ponteiro para a estrutura que armazena uma matriz.
 */
void MatrixFree(tMatrix* matrix){
    int i = 0;

    if(matrix){
        if(matrix->data){
            for(i = 0; i < matrix->rows; i++){
                if(matrix->data[i]){
                    free(matrix->data[i]);
                    //printf("passei aqui\n");
                }
                else{
                    printf("tentou liberar o ponteiro da data linha jah nulo!\n");
                    exit(1);
                }
            }
            free(matrix->data);
        }
        else{
            printf("tentou liberar o ponteiro data jah nulo!\n");
            exit(1);
        }
        free(matrix);
    }
    else{
        printf("tentou liberar o ponteiro de matriz ja nulo!\n");
        exit(1);
    }        
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 */
void MatrixRead(tMatrix* matrix){
    int i = 0, j = 0;

    //matrix = MatrixCreate(matrix->rows, matrix->cols);
    scanf("%*[^0-9]");
    for(i = 0; i < matrix->rows; i++){
        for(j = 0; j < matrix->cols; j++){
            scanf("%d", &matrix->data[i][j]);
        }
    } 
    scanf("%*[^0-9]");
    return;
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix* matrix){
    int i = 0, j = 0;
    //printf("\n");
    for(i = 0; i < matrix->rows; i++){
        printf("|");
        for(j = 0; j < matrix->cols;j++){
            if(j != matrix->cols-1){
                printf("%d ", matrix->data[i][j]);
            }
            else {
                printf("%d", matrix->data[i][j]);
            }
            
        }
        printf("|\n");
    } 
    //printf("\n");
    return;    
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix* matrix1, tMatrix* matrix2){
    if(matrix1->cols == matrix2->cols && matrix1->rows == matrix2->rows){
        return 1;
    }
    else{
        return 0;
    }
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix* matrix1, tMatrix* matrix2){
    if(matrix1->cols == matrix2->cols && matrix1->rows == matrix2->rows){
        return 1;
    }
    else{
        return 0;
    }    
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix* matrix1, tMatrix* matrix2){
    if(matrix1->cols == matrix2->rows){
        return 1;
    }
    else{
        return 0;
    }
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix* MatrixAdd(tMatrix* matrix1, tMatrix* matrix2){
    
    if(PossibleMatrixSum(matrix1, matrix2)){
        tMatrix *res;
        int i = 0, j = 0;
        int cols = matrix2->cols, rows =  matrix2->rows;
        res =  MatrixCreate(rows, cols);
        for(i = 0; i < rows;i++){
            for(j = 0; j < cols; j++){
                res->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
            }
        }
        return res;
    }
    
    
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix* MatrixSub(tMatrix* matrix1, tMatrix* matrix2){

    if(PossibleMatrixSub(matrix1, matrix2)){
        tMatrix *res;
        int i = 0, j = 0;
        int cols = matrix2->cols, rows =  matrix2->rows;
        res =  MatrixCreate(rows, cols);
        for(i = 0; i < rows;i++){
            for(j = 0; j < cols; j++){
                res->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
            }
        }
        return res;
    }
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix* MatrixMultiply(tMatrix* matrix1, tMatrix* matrix2){
    if(PossibleMatrixMultiply(matrix1, matrix2)){
        tMatrix *res;
        int i = 0, j = 0, k = 0;
        int cols = matrix2->cols, rows =  matrix1->rows;
        
        int idx = matrix1->cols; 
        
        res =  MatrixCreate(rows, cols);

        for(i = 0; i < rows;i++){
            for(j = 0; j < cols; j++){
                res->data[i][j] = 0;
                for(k=0; k< idx;k++){
                    res->data[i][j] += matrix1->data[i][k]*matrix2->data[k][j];
                }
            }
        }
        return res;
    }
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix* TransposeMatrix(tMatrix* matrix){
    tMatrix *res;
    int i = 0, j = 0;
    int cols = matrix->cols, rows =  matrix->rows;
    
    
    res =  MatrixCreate(cols, rows);

    for(i = 0; i < cols; i++){
        for(j = 0; j < rows; j++){
            res->data[i][j] = matrix->data[j][i];
        }
    }
    return res;
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix* MatrixMultiplyByScalar(tMatrix* matrix, int scalar){
    int i = 0, j = 0, cols = matrix->cols, rows = matrix->rows;
    tMatrix * res;
    res = MatrixCreate(rows, cols);

    //matrix = MatrixCreate(matrix->rows, matrix->cols);
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            res->data[i][j] = (matrix->data[i][j])*scalar;
        }
    }
    return res;
}
