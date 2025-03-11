#include "aluno.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TAM_MAX_NOME 40
#define TAM_MAX_DT_NAS 40
#define TAM_MAX_CURSO 40
#define TAM_MAX_PERIODO 40

struct aluno {
    char nomeAluno[TAM_MAX_NOME];
    char curso[TAM_MAX_CURSO];
    char periodo[TAM_MAX_PERIODO];
    char dtNas[TAM_MAX_CURSO];
    float cra;
    int periodoConclusao;
};



Aluno** CriaVetorAlunos(int numeroAlunos){

    Aluno ** alunos;

    alunos = (Aluno**)malloc(sizeof(Aluno*)*numeroAlunos);

    
    return alunos;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno * aluno;

    aluno = (Aluno*)malloc(sizeof(Aluno));

    aluno->cra = CRA;
    aluno->periodoConclusao = percConclusao;
    strcpy(aluno->nomeAluno, nome);
    strcpy(aluno->dtNas, dtNasc);
    strcpy(aluno->curso, cursoUfes);
    strcpy(aluno->periodo, periodoIngresso);


    return aluno;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    char nomeAluno[TAM_MAX_NOME];
    char curso[TAM_MAX_CURSO];
    char periodo[TAM_MAX_PERIODO];
    char dtNas[TAM_MAX_CURSO];
    float cra;
    int periodoConclusao;
    
    int i = 0;

    Aluno * alunoAtual;

    for(i =0; i < numeroAlunos; i++){
        scanf("%*[^a-zA-Z]");
        scanf("%[^\n]", nomeAluno);
        scanf("%*[\n]");
        scanf("%[^\n]", dtNas);
        scanf("%*[\n]");
        scanf("%[^\n]", curso);
        scanf("%*[\n]");
        scanf("%[^\n]", periodo);
        scanf("%*[\n]");
        scanf("%d\n", &periodoConclusao);
        scanf("%f\n", &cra);
        alunoAtual = CriaAluno(nomeAluno, dtNas, curso, periodo, periodoConclusao, cra);
        vetorAlunos[i] = alunoAtual;

    }

    



}

void LiberaAlunos(Aluno** alunos, int numeroAlunos){

    if(alunos){

        int i;
        for(i = 0; i < numeroAlunos; i++){
            if(alunos[i]){
                free(alunos[i]);
            }
        }
        free(alunos);    
    }
    

}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    FILE * arquivo;
    arquivo = fopen(fileName, "wb");
   // fileName  = fopen("arquivo.bin", "wb");
    int tamanho = 0;
    int numeroBytes = 0;
    numeroBytes += sizeof(int)*fwrite(&numeroAlunos, sizeof(int), 1, arquivo);

    for(int i = 0; i < numeroAlunos; i++){

        tamanho = strlen(alunos[i]->nomeAluno) ; 
        numeroBytes += sizeof(int)*fwrite(&tamanho, sizeof(int), 1, arquivo);
        numeroBytes += sizeof(char)*fwrite(alunos[i]->nomeAluno, sizeof(char), tamanho, arquivo);

        tamanho = strlen(alunos[i]->dtNas) ; 
        numeroBytes += sizeof(int)*fwrite(&tamanho, sizeof(int), 1, arquivo);
        numeroBytes += sizeof(char)*fwrite(alunos[i]->dtNas, sizeof(char), tamanho, arquivo);

        tamanho = strlen(alunos[i]->curso) ; 
        numeroBytes += sizeof(int)*fwrite(&tamanho, sizeof(int), 1, arquivo);
        numeroBytes += sizeof(char)*fwrite(alunos[i]->curso, sizeof(char), tamanho, arquivo);

        tamanho = strlen(alunos[i]->periodo) ; 
        numeroBytes += sizeof(int)*fwrite(&tamanho, sizeof(int), 1, arquivo);
        numeroBytes += sizeof(char)*fwrite(alunos[i]->periodo, sizeof(char), tamanho, arquivo);


        numeroBytes += sizeof(int)*fwrite(&alunos[i]->cra, sizeof(int), 1, arquivo);
        numeroBytes += sizeof(float)*fwrite(&alunos[i]->periodoConclusao, sizeof(float), 1, arquivo);
        
    }
    printf("Numero de bytes salvos: %d\n", numeroBytes);
    fclose(arquivo);

}

void CarregaAlunosBinario(Aluno **alunos, char *fileName){
    int tamanho;
    FILE * arquivo;
    arquivo = fopen(fileName, "rb");
    int numeroAlunos=0;
    fread(&numeroAlunos, sizeof(int), 1, arquivo);

    char nomeAluno[TAM_MAX_NOME];
    char curso[TAM_MAX_CURSO];
    char periodo[TAM_MAX_PERIODO];
    char dtNas[TAM_MAX_CURSO];
    float cra;
    int periodoConclusao;

    memset(nomeAluno, 0, 40);
    memset(curso, 0, 40);
    memset(periodo, 0, 40);
    memset(dtNas, 0, 40);

    for(int i=0; i < numeroAlunos; i++) {
        

        // Lendo nomeAluno
        fread(&tamanho, sizeof(int), 1, arquivo);
        fread(nomeAluno, sizeof(char), tamanho, arquivo);
        nomeAluno[tamanho] = '\0';
        // Lendo dtNas
        fread(&tamanho, sizeof(int), 1, arquivo);
        fread(dtNas, sizeof(char), tamanho, arquivo);
        dtNas[tamanho] = '\0';

        // Lendo curso
        fread(&tamanho, sizeof(int), 1, arquivo);
        fread(curso, sizeof(char), tamanho, arquivo);
        curso[tamanho] = '\0';
        // Lendo periodo
        fread(&tamanho, sizeof(int), 1, arquivo);
        fread(periodo, sizeof(char), tamanho, arquivo);
        periodo[tamanho] = '\0';
        // Lendo valores numéricos diretamente
        fread(&cra, sizeof(float), 1, arquivo);
        fread(&periodoConclusao, sizeof(int), 1, arquivo);
        
        alunos[i] = CriaAluno(nomeAluno, dtNas, curso, periodo, periodoConclusao, cra);
    }
    fclose(arquivo);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    
    for(int i = 0; i < numeroAlunos; i++){
        printf("Aluno %d:\n", i);
        imprimeAluno(alunos[i]);
    }
        
        

}

void imprimeAluno (Aluno * aluno){
    printf("Nome: %s\nData Nascimento: %s\nCurso: %s\nPeriodo Ingresso: %s\n%% Conclusao do Curso: %d\nCRA: %.2f\n", aluno->nomeAluno, aluno->dtNas, aluno->curso, aluno->periodo, aluno->periodoConclusao, aluno->cra);

}