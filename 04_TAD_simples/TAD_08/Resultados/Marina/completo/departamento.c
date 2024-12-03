#include <math.h>
#include "departamento.h"
#include <string.h>

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){
    tDepartamento depto;
    strcpy(depto.c1, c1);
    strcpy(depto.c2, c2);
    strcpy(depto.c3, c3);
    strcpy(depto.nome, nome);
    strcpy(depto.diretor, diretor);

    depto.m1 = m1;
    depto.m2 = m2;
    depto.m3 = m3;
    depto.media_geral = calculaMediaGeralDepartamento(depto);
    return depto;
}

void imprimeAtributosDepartamento (tDepartamento depto){

    printf("ATRIBUTOS:\ndepartamento => %s\ndiretor => %s\ncurso1 => %s, media1 => %d\ncurso2 => %s, media2 => %d\ncurso3 => %s, media3 => %d\nmedia geral => %.2f\ndesvio padrao => %.2f\n\n", depto.nome, depto.diretor, depto.c1, depto.m1, depto.c2, depto.m2, depto.c3, depto.m3, depto.media_geral, calculaDesvioPadraoDepartamento(depto));
    return;
}

int validaMediaDepartamento (int media){
    return (media>=0 && media<=10) ? 1 : 0;
}

double calculaDesvioPadraoDepartamento(tDepartamento depto){
    double media = 0, somatorio = 0;
    media = calculaMediaGeralDepartamento(depto);
    int i = 0;
    somatorio = (pow((depto.m1 - depto.media_geral), 2) + pow((depto.m2 - depto.media_geral), 2) + pow((depto.m3 - depto.media_geral), 2));
    somatorio = somatorio/3.0;
    return sqrt(somatorio);
}

double calculaMediaGeralDepartamento(tDepartamento depto){
    return (double)(depto.m1 + depto.m2 + depto.m3)/3.0;
}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho){
    int idxMaior = 0;
    tDepartamento maior = d[0];
    int i = 0, j = 0;

    for(i = 0; i < tamanho; i++){
        idxMaior = i;
        maior = d[i];
        for(j = i; j < tamanho; j++){
            if(maior.media_geral < d[j].media_geral){
                maior = d[j];
                idxMaior = j;
            }
        }
        if(d[i].media_geral < maior.media_geral){
            tDepartamento aux;
            aux = d[i];
            d[i] = maior;
            d[idxMaior] = aux;
        }
    }
    return;
}

