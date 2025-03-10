#include "base_alunos.h"
#include "aluno.h"
#include <string.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar uma base de alunos.
 */
struct BaseAlunos {
    tAluno **alunos;
    int qtd;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos(){
    tBaseAlunos * base;
    base = (tBaseAlunos*)malloc(sizeof(tBaseAlunos));



    return base;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos){
    if(baseAlunos){
        if(baseAlunos->alunos){

            for(int i = 0; i < baseAlunos->qtd; i++){
                if(baseAlunos->alunos[i]){
                    DestruirAluno(baseAlunos->alunos[i]);
                }
            }
            free(baseAlunos->alunos);
        }
        free(baseAlunos);
    }
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){
    baseAlunos->alunos;
    int qtd = 0;
    FILE * arquivo;
    arquivo = fopen(nomeArquivo, "rb");

    fread(&qtd, sizeof(int), 1, arquivo);
    baseAlunos->alunos = (tAluno**)malloc(sizeof(tAluno*)*qtd);
    baseAlunos->qtd = qtd;
    for(int i = 0; i < qtd; i++){
        baseAlunos->alunos[i] = LeAluno(arquivo);
    }
    fclose(arquivo);

}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){
    float somador = 0;
    for(int i = 0; i < baseAlunos->qtd; i++){
        somador+= GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }
    return somador/baseAlunos->qtd;
}