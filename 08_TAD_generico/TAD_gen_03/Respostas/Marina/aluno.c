#include "aluno.h"

#define MAX_TAM_NAME 51

struct Aluno {
    char nome[MAX_TAM_NAME];
    float nota;
    char genero;

};

/**
 * @brief Aloca memoria para um aluno
 * 
 * @return A estrutura tAluno inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
tAluno *CriaAluno(){
    tAluno  * aluno;

    aluno = (tAluno*)malloc(sizeof(tAluno));

    return aluno;
}
/**
 * @brief Libera a memoria alocada para um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * Dica: Foi usado data_type para generalizar a funcao e usar na estrutura Vector. Por isso, é necessário fazer um cast para tAluno* dentro da função.
*/
void DestroiAluno(data_type aluno){
    if(aluno){
        free(aluno);
    }
}

/**
 * @brief Le os dados de um aluno
 * 
 * @param aluno Ponteiro para o aluno
*/
void LeAluno(tAluno *aluno){

    scanf("%[^;]", aluno->nome);
    scanf("%*[;]");
    scanf("%c;", &aluno->genero);
    scanf("%f\n", &aluno->nota);

    return;

}

/**
 * @brief Retorna o genero de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return char Genero do aluno
*/
char GetGeneroAluno(tAluno *aluno){
    return aluno->genero;
}

/**
 * @brief Retorna a nota de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return float Nota do aluno
*/
float GetNotaAluno(tAluno *aluno){
    return aluno->nota;
}