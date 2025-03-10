#include "aluno.h"
#include <stdio.h>

int main(){

    Aluno ** alunos;
    int qtd = 0;
    printf("Digite o numero de alunos: ");
    scanf("%d\n", &qtd);
    
    alunos=CriaVetorAlunos(qtd);
    
    LeAlunos(alunos, qtd);
    SalvaAlunosBinario(alunos, "alunos.bin", qtd);
    LiberaAlunos(alunos, qtd);


    alunos=CriaVetorAlunos(qtd);
    CarregaAlunosBinario(alunos, "alunos.bin");
    
    ImprimeAlunos(alunos, qtd);
    LiberaAlunos(alunos, qtd);
    return 0;
}
