#include "matrix_utils.h"

void ImprimeMenu();

int main(){
    int rows1 = 0, rows2 = 0, cols1 = 0, cols2 = 0;
    tMatrix *m1, *m2;

    scanf("%d %d\n", &rows1, &cols1);
    //printf("%d %d", rows1, cols1);
    m1 = MatrixCreate(rows1, cols1);
    MatrixRead(m1);
   // MatrixPrint(m1);

    scanf("%d %d\n", &rows2, &cols2);
   // printf("%d %d\n", rows2, cols2);
    m2 = MatrixCreate(rows2, cols2);
    MatrixRead(m2);
   // MatrixPrint(m2);
    scanf("%*[^0-9]");
    
    int op;

    while(1){
        ImprimeMenu();
        scanf("%d\n", &op);
        if(op == 6){
            break;
        }
        else if(op == 1){
            if(PossibleMatrixSum(m1,m2)){
                tMatrix *res;
                res = MatrixAdd(m1,m2);
                MatrixPrint(res);
                MatrixFree(res);
            }
            else {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }
        else if(op == 2){
            if(PossibleMatrixSub(m1, m2)){
                tMatrix *res;
                res = MatrixSub(m1,m2);
                MatrixPrint(res);
                MatrixFree(res);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }
        else if(op == 3){
            if(PossibleMatrixMultiply(m1, m2)){
                tMatrix *res;
                res = MatrixMultiply(m1,m2);
                MatrixPrint(res);
                MatrixFree(res);
            }
            else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }
        }
        else if(op == 4){
            int scalar = 0, m;
            tMatrix *res;

            scanf("%d %d\n", &scalar, &m);
            if(m == 1){
                res = MatrixMultiplyByScalar(m1, scalar);
                MatrixFree(m1);
                m1 = res;
                MatrixPrint(m1);
            }
            else if(m == 2){
                res = MatrixMultiplyByScalar(m2, scalar);
                MatrixFree(m2);
                m2 = res;
                MatrixPrint(m2);
            }
        }
        else if(op == 5){
            tMatrix *res;
            res = TransposeMatrix(m1);
            MatrixPrint(res);
            MatrixFree(res);
           // printf("\n");
            res = TransposeMatrix(m2);
            MatrixPrint(res);
            MatrixFree(res);
        }

    }

    MatrixFree(m1);
    MatrixFree(m2);


    return 0;
}

void ImprimeMenu(){
    printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida:\n"); 
}