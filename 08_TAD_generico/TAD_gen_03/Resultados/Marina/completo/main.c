#include "relatorio.h"
#include "aluno.h"
#include <stdio.h>

int main(){
    int qtd = 0, i = 0;
    scanf("%d\n", &qtd);

    Vector * vector;
    vector = VectorConstruct();
    
    tAluno * aluno;

    for(i = 0; i < qtd; i++){
        aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(vector, aluno);

    }

    ImprimeRelatorio(vector);

    VectorDestroy(vector, DestroiAluno);
    return 0;
}
