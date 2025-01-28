#include <stdio.h>
#include "aluno.h"

void OrdenaVetorAlunos(tAluno ** alunos, int qtd);

int main(){
    int qtd = 1, i = 0;

    scanf("%d", &qtd);
    //char string;
    //scanf("%c", &string);
    tAluno **alunos;
    alunos = (tAluno**)malloc(sizeof(tAluno*)*qtd);

    for(i = 0; i < qtd; i++){
        alunos[i] = CriaAluno();
    }

    for(i = 0; i < qtd; i++){
        LeAluno(alunos[i]);
    }
   OrdenaVetorAlunos(alunos, qtd);

    for(i = 0; i < qtd; i++){
        if(VerificaAprovacao(alunos[i])){
            ImprimeAluno(alunos[i]);
        }
        ApagaAluno(alunos[i]);
    }
    free(alunos);
    return 0;
}

void OrdenaVetorAlunos(tAluno ** alunos, int qtd){
    int i = 0, j = 0;
    tAluno *AlunoMenor;

    AlunoMenor = CriaAluno(); 
    int idxMenor = 0;
    
    for(i = 0; i < qtd-1; i++){
        *AlunoMenor = *alunos[i];  
        idxMenor = i;
        for(j = i+1; j < qtd; j++){
            if(ComparaMatricula(AlunoMenor, alunos[j]) == 1){
                *AlunoMenor = *alunos[j];  
                idxMenor = j;
            }
        }
        if(ComparaMatricula(alunos[i], AlunoMenor)){
            tAluno *alunosAux;
            alunosAux = CriaAluno();
            *(alunosAux) = *(alunos[i]);
            *alunos[i] = *alunos[idxMenor]; 
            *alunos[idxMenor] = *(alunosAux);
            free(alunosAux);
        }
    }
    free(AlunoMenor);
}