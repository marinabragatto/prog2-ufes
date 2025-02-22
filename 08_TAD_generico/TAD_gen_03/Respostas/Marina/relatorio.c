#include "relatorio.h"
#include "aluno.h"


/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos){
    int tam = 0, i = 0;
    float notas = 0;
    char genero;
    int qtdF = 0, qtdM = 0, qtdO = 0, qtdAp = 0;

    tam = VectorSize(alunos);
    tAluno * aluno;
    for(i = 0; i < tam; i++){
        aluno = VectorGet(alunos, i);
        notas += GetNotaAluno(aluno);
        genero = GetGeneroAluno(aluno); 
        if(genero == 'F'){
            qtdF++;
        }
        else if(genero == 'M'){
            qtdM++;
        }
        else if(genero == 'O'){
            qtdO++;
        }

        if(GetNotaAluno(aluno) >= 6){
            qtdAp++;
        }
    }
    notas = notas/tam;
    printf("Media das notas: %.2f\n", notas);
    
    float porcAprov , porcMas = 0, porcFem = 0, porcOu = 0;
    if(tam != 0){
        porcAprov = (qtdAp/(float)tam)*100;
        porcFem = (qtdF/(float)tam)*100;
        porcMas = (qtdM/(float)tam)*100;
        porcOu = (qtdO/(float)tam)*100;
    }


    printf("Porcentagem de alunos aprovados: %.2f%%\n",porcAprov);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n",porcMas);
    printf("Feminino: %.2f%%\n", porcFem);
    printf("Outro: %.2f%%\n", porcOu);
}