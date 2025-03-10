#include "aluno.h"
#include <string.h>
#include <stdlib.h>

#define TAM_MAX_NOME 100
#define TAM_MAX_DT_NAS 11
#define TAM_MAX_CURSO 50

/**
 * @brief Estrutura para representar um aluno.
 */
struct Aluno {
    char nome[TAM_MAX_NOME];
    char dataNascimento[TAM_MAX_DT_NAS]; 
    char curso[TAM_MAX_CURSO]; 
    int periodo; 
    float coeficienteRendimento;
};
/*
• Uma string de tamanho máximo 100 contendo o nome do aluno. 
• Uma string de tamanho máximo 11 para armazenar a data de nascimento. 
• Uma string de tamanho máximo 50 com o nome do curso. 

*/

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento){
    tAluno * aluno;

    aluno = (tAluno*)malloc(sizeof(tAluno));

    aluno->periodo = periodo;
    aluno->coeficienteRendimento = coeficienteRendimento;

    strcpy(aluno->curso, curso);
    strcpy(aluno->dataNascimento, dataNascimento);
    strcpy(aluno->nome, nome);   


    return aluno;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno){
    if(aluno){
        free(aluno);
    }
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario){
  /*  • Uma string de tamanho máximo 100 contendo o nome do aluno. 
• Uma string de tamanho máximo 11 para armazenar a data de nascimento. 
• Uma string de tamanho máximo 50 com o nome do curso. 
• Um float de 4 bytes com o coeficiente de rendimento do aluno.*/
    tAluno * aluno;

    char nome[TAM_MAX_NOME];
    char dataNascimento[TAM_MAX_DT_NAS]; 
    char curso[TAM_MAX_CURSO]; 

    int periodo; 
    float coeficienteRendimento;
    
    //arquivo_binario

    fread(nome, sizeof(char), TAM_MAX_NOME, arquivo_binario);

    //printf("%d", tamanho);
    fread(dataNascimento, sizeof(char), TAM_MAX_DT_NAS, arquivo_binario);

   // printf("%d", tamanho);

    fread(curso, sizeof(char), TAM_MAX_CURSO, arquivo_binario);

    //printf("%d", tamanho);
    fread(&periodo, sizeof(int), 1, arquivo_binario);
    fread(&coeficienteRendimento, sizeof(float), 1, arquivo_binario);
    
    aluno = CriarAluno(nome, dataNascimento, curso, periodo, coeficienteRendimento);


    return aluno;
    
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno){
    return aluno->coeficienteRendimento;
}