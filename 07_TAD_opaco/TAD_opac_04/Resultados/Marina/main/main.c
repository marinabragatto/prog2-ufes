#include <stdio.h>
#include "aluno.h"

void OrdenaVetor(tAluno ** alunos, int qtd);

int main(){
    int qtd = 0;
    int i = 0;
    scanf("%d", &qtd);
    tAluno **alunos;
    alunos = (tAluno**)malloc(sizeof(tAluno*)*qtd);

    for(i = 0; i < qtd;i++){
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);    
    }
    OrdenaVetor(alunos, qtd);
    for(i  = 0; i < qtd;i++){
        if(VerificaAprovacao(alunos[i])){
            ImprimeAluno(alunos[i]);
        }
        ApagaAluno(alunos[i]);

    }

    free(alunos);
    
    return 0;
}

void OrdenaVetor(tAluno ** alunos, int qtd){
    int i = 0, j = 0;
    int idxMenor = 0;
    tAluno * alunoMenor;
    //alunoMenor = CriaAluno();


    for(i = 0; i < qtd-1;i++){
        idxMenor = i;

        alunoMenor = alunos[i];

        for(j = i+1; j <qtd;j++){
            if(ComparaMatricula(alunoMenor, alunos[j])  == 1){
                alunoMenor = alunos[j];
                idxMenor = j;
            }

        }
        if(ComparaMatricula(alunos[i], alunoMenor)== 1){
            tAluno *alunoAux; 
            alunoAux = alunos[i];
            alunos[i] = alunos[idxMenor];
            alunos[idxMenor] = alunoAux;
            //free(alunoAux);
        }
    }

}