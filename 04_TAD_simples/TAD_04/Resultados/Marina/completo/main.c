#include "aluno.h"
#include <stdio.h>

void leVetorAlunos(tAluno alunos[], int qtd);
void impremeVetorAlunos(tAluno alunos[], int qtd);
int buscaIdxMenor(tAluno alunos[], int inicio, int fim);
int ehMenorMatriculaAqMatriculaB(int matriculaA, int matriculaB);
void trocaPosicao(int idxMenor, int i, tAluno alunos[]);
void ordenaVetor(tAluno alunos[], int qtd);

int main(){
    int qtd = 0;
    
    scanf("%d", &qtd);
    tAluno alunos[qtd];
    leVetorAlunos(alunos, qtd);
    impremeVetorAlunos(alunos, qtd);
}

void impremeVetorAlunos(tAluno alunos[], int qtd){
    int i = 0;
    ordenaVetor(alunos, qtd);
    for (i = 0; i < qtd; i++){
        if(VerificaAprovacao(alunos[i])){
            ImprimeAluno(alunos[i]);
        }
        
    }
}

void leVetorAlunos(tAluno alunos[], int qtd){
    int i = 0;
    for (i = 0; i < qtd; i++){
        alunos[i] = LeAluno();
    }
    return;
}

void ordenaVetor(tAluno alunos[], int qtd){
    int idxMenor = 0, menor = alunos[idxMenor].matricula, i = 0;


    for (i = 0; i < qtd-1; i++){
        idxMenor = buscaIdxMenor(alunos, i + 1, qtd);
        if(ehMenorMatriculaAqMatriculaB(alunos[idxMenor].matricula, alunos[i].matricula)){
            trocaPosicao(idxMenor, i, alunos);
        }
    }
    //pega
}

int buscaIdxMenor(tAluno alunos[], int inicio, int fim){
    int idxMenor = inicio, menor = alunos[idxMenor].matricula, i = 0;

    for(i = inicio; i < fim; i++){
        if (menor > alunos[i].matricula){
            idxMenor = i;
            menor = alunos[i].matricula;
        }
    }
    return idxMenor;
}
int ehMenorMatriculaAqMatriculaB(int matriculaA, int matriculaB){
    if(matriculaA < matriculaB){
        return 1;
    }
    else {
        return 0;
    }
}

void trocaPosicao(int idxMenor, int i, tAluno alunos[]){
    tAluno aux;
    aux = alunos[idxMenor];
    alunos[idxMenor]= alunos[i];
    alunos[i] = aux;
    return;
}