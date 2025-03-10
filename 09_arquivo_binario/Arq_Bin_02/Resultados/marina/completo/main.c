#include "base_alunos.h"
#include "aluno.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    char nomeArq[200];
    scanf("%[^\n]", nomeArq);
    tBaseAlunos * base;
    base = CriarBaseAlunos();
    LerBaseAlunos(base, nomeArq);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(base));

    DestruirBaseAlunos(base);
    return 0;

}