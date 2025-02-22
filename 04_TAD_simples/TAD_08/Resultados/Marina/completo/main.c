#include "departamento.h"
#include <stdio.h>

int main(){
    char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX], nome[STRING_MAX], diretor[STRING_MAX];
    int m1 = 0, m2 = 0, m3 = 0;
    int qtd = 0, i = 0;
    scanf("%d\n", &qtd);

    tDepartamento d[qtd];

    for(i = 0; i < qtd; i++){
        scanf("%[^\n]", nome);
        scanf("%*[\n]");
        scanf("%[^\n]", diretor);
        scanf("%*[\n]");
        scanf("%[^\n]", c1);
        scanf("%*[\n]");
        scanf("%[^\n]", c2);
        scanf("%*[\n]");
        scanf("%[^\n]", c3);
        scanf("%*[\n]");
        scanf("%d %d %d\n", &m1, &m2, &m3);
        //printf("%s ", nome);
        d[i] = criaDepartamento(c1,c2,c3,nome,m1,m2,m3,diretor);
    }

    ordenaPorMediaDepartamentos(d, qtd);

    for(i = 0; i < qtd; i++){
        imprimeAtributosDepartamento(d[i]);
    }
    
    
    return 0;
}