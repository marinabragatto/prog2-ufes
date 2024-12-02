#include "matrix_utils.h"
#include <stdio.h>

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado.
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix MatrixCreate(int rows, int cols){
    tMatrix matrix;
    matrix.cols = cols;
    matrix.rows = rows;
    return matrix;
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 * @return A matriz lida.
 */
tMatrix MatrixRead(tMatrix matrix){
    int i = 0, j = 0;
    for(i = 0; i < matrix.rows; i++){
        for(j = 0; j < matrix.cols; j++){
            scanf("%d", &matrix.data[i][j]);
        }
    }
    return matrix;
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix matrix){
    int i = 0, j = 0;
    
    for(i = 0; i < matrix.rows; i++){
        printf("|");
        for(j = 0; j < matrix.cols; j++){
            if(j != matrix.cols - 1){
                printf("%d ", matrix.data[i][j]);
            }
            else {
                printf("%d|", matrix.data[i][j]);
            }
            
        }
        printf("\n");
    }
    printf("\n");
    return;
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.cols == matrix2.cols && matrix1.rows == matrix2.rows){
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
int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.cols == matrix2.cols && matrix1.rows == matrix2.rows){
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
int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.cols == matrix2.rows){
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2){
    tMatrix matrix3;
    matrix3 = MatrixCreate(matrix1.rows, matrix1.cols);
    int j = 0, i = 0;

    for(i = 0; i < matrix3.rows;i++){
        for(j = 0; j < matrix3.cols;j++){
            matrix3.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];        
        }
    }
    return matrix3;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2){
    tMatrix matrix3;
    matrix3 = MatrixCreate(matrix1.rows, matrix1.cols);
    int j = 0, i = 0;

    for(i = 0; i < matrix3.rows;i++){
        for(j = 0; j < matrix3.cols;j++){
            matrix3.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];        
        }
    }
    return matrix3;
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    tMatrix matrix3;
    matrix3 = MatrixCreate(matrix1.rows, matrix2.cols);
    int i = 0, j = 0, cont = 0;

    for(i = 0; i < matrix3.rows;i++){
        for(j = 0; j < matrix3.cols; j++){
            matrix3.data[i][j] = 0;
            for(cont = 0; cont < matrix1.cols; cont++){
                matrix3.data[i][j] += matrix1.data[i][cont]*matrix2.data[cont][j];
            }
        }
    }
    return matrix3;
}
/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix TransposeMatrix(tMatrix matrix){
    tMatrix inversa;
    inversa = MatrixCreate(matrix.cols, matrix.rows);
    int j = 0, i = 0;

    for(i = 0; i < inversa.rows;i++){
        for(j = 0; j < inversa.cols;j++){
            inversa.data[i][j] = matrix.data[j][i];        
        }
    }

    return inversa;
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar){
    int j = 0, i = 0;

    for(i = 0; i < matrix.rows;i++){
        for(j = 0; j < matrix.cols;j++){
            matrix.data[i][j] = scalar*matrix.data[i][j];        
        }
    }
    return matrix;
}