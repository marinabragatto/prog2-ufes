#include <stdio.h>
#include "vetor.h"

int soma(int n1, int n2);
int multiplica(int n1, int n2);

int main(){
    Vetor *vetor;
    Vetor vt;
    vetor = &vt;

    LeVetor(vetor);
    int sum = 0, produto = 0;
    sum = AplicarOperacaoVetor(vetor,soma);
    produto = AplicarOperacaoVetor(vetor, multiplica);
    printf("Soma: %d\nProduto: %d\n", sum, produto);

    /*Vetor vetor;

    LeVetor(&vetor);
    int sum = 0, produto = 0;
    sum = AplicarOperacaoVetor(&vetor,soma);
    produto = AplicarOperacaoVetor(&vetor, multiplica);
    printf("Soma: %d\nProduto: %d\n", sum, produto);
   */
    return 0;
}

int soma(int n1, int n2){
    return n1+n2;
}
int multiplica(int n1, int n2){
    return n1*n2;
}