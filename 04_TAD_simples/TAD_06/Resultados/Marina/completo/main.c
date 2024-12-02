#include <stdio.h>
#include "matrix_utils.h"

void imprimeMenu();

int main(){
    int l1 = 0, c1 = 0, l2 = 0, c2 = 0;

    scanf("%d %d", &l1, &c1);
    tMatrix Matrix1;
    Matrix1 = MatrixCreate(l1, c1);
    Matrix1 = MatrixRead(Matrix1);
    //MatrixPrint(Matrix1);

    scanf("%d %d", &l2, &c2);
    tMatrix Matrix2;
    Matrix2 = MatrixCreate(l2, c2);
    Matrix2 = MatrixRead(Matrix2);
    //MatrixPrint(Matrix2);

    int op = 0;
    while(1){
        imprimeMenu();
        scanf("%d", &op);
        if(op == 6){
            break;
        }
        else if(op == 1){
            if(PossibleMatrixSum(Matrix1, Matrix2)){
                tMatrix Matrix3;
                Matrix3 =  MatrixCreate(Matrix1.rows, Matrix1.cols);
                Matrix3 = MatrixAdd(Matrix1, Matrix2);
                MatrixPrint(Matrix3);
            }
            else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        else if(op == 2){
            if(PossibleMatrixSub(Matrix1, Matrix2)){
                tMatrix Matrix3;
                Matrix3 =  MatrixCreate(Matrix1.rows, Matrix1.cols);
                Matrix3 = MatrixSub(Matrix1, Matrix2);
                MatrixPrint(Matrix3);
            }
            else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        if(op == 3){
            if(PossibleMatrixMultiply(Matrix1, Matrix2)){
                tMatrix Matrix3;
                Matrix3 =  MatrixCreate(Matrix1.rows, Matrix2.cols);
                Matrix3 = MatrixMultiply(Matrix1, Matrix2);
                MatrixPrint(Matrix3);
            }
            else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
        }
        else if(op == 4){
            int m = 0, scalar = 0;
            
            scanf("%d", &scalar);
            scanf("%d", &m);
            if(m == 1){
                Matrix1 = MatrixMultiplyByScalar(Matrix1, scalar);
                MatrixPrint(Matrix1);
            }
            else {
                Matrix2 = MatrixMultiplyByScalar(Matrix2, scalar);
                MatrixPrint(Matrix2);
            }
        }
        else if(op == 5){
            tMatrix m1, m2;
            m1 = MatrixCreate(Matrix1.cols, Matrix1.rows);
            m1 = TransposeMatrix(Matrix1);
            MatrixPrint(m1);
            m2 = MatrixCreate(Matrix2.cols, Matrix2.rows);
            m2 = TransposeMatrix(Matrix2);
            MatrixPrint(m2);
        }

    }

    return 0;
}

void imprimeMenu(){
    printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: \n");
    return;
}