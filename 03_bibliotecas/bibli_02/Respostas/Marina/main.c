#include <stdio.h>
#include "matrix_utils.h"

void menu_print();
void execute_op(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int option);

int main(){
    int rows1 = 0, rows2 = 0, cols1 = 0, cols2 = 0, op = 0;

    scanf("%d %d", rows1, cols1); 
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d", rows2, cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

    while(1){
        menu_print();
        scanf("%d", &op);
        if(op == 6){
            break;
        }
        void execute_op();
    }

    return 0;
}

void menu_print(){
    printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida:\n");
    return;
}

void execute_op(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int option){
    if(option == 1){
        if(possible_matrix_sum(rows1, cols1, rows2, cols2)){
            int result[rows1][cols1];
            matrix_add(rows1, cols1, matrix1[rows1][cols1], rows2, cols2, matrix2[rows2][cols2], result[rows1][cols1]);
            matrix_print(rows1, cols1, result[rows1][cols1]);
        }
        else {
            printf("Erro: as dimensoes da matriz nao correspondem\n");
        }
    }
    else if(option == 2){
        if(possible_matrix_sub(rows1, cols1, rows2, cols2)){
            int result[rows1][cols1];
            matrix_sub(rows1, cols1, matrix1[rows1][cols1], rows2, cols2, matrix2[rows2][cols2], result[rows1][cols1]);
            matrix_print(rows1, cols1, result[rows1][cols1]);
        }
        else {
            printf("Erro: as dimensoes da matriz nao correspondem\n");
        }
    }
    else if(option == 3){
        if(possible_matrix_multiply(cols1, rows2)){
            int result[rows1][cols2];
            matrix_multiply(rows1, cols1, matrix1[rows1][cols1], rows2, cols2, matrix2[rows2][cols2], result[rows1][cols2]);
            matrix_print(rows1, cols2, result[rows1][cols2]);
        }
        else {
            printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
        }
    }
    else if(option == 4){
        int scalar = 0, matrix;
        scanf("%d", &scalar);
        scanf("%d", &matrix);
        if(matrix == 1){
            scalar_multiply(rows1, cols1, matrix1[rows1][cols1], scalar);
            matrix_print(rows1, cols1, matrix1[rows1][cols1]);
        }
        else if(matrix == 2){
            scalar_multiply(rows2, cols2, matrix2[rows2][cols2], scalar);
            matrix_print(rows2, cols2, matrix2[rows2][cols2]);
        }
    }
    else if(option == 5){
        int result1[cols1][rows1];
        int result2[cols2][rows2];
        transpose_matrix(rows1, cols1, matrix1[rows1][cols1], result1[cols1][rows1]);
        transpose_matrix(rows2, cols2, matrix1[rows2][cols2], result2[cols2][rows2]);
        matrix_print(rows1, cols1, result1[cols1][rows1]);
        printf("\n");
        matrix_print(rows2, cols2, result2[cols2][rows2]);
    }
    
    return;

}