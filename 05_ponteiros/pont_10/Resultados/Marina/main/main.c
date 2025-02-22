#include <stdio.h>
#include "pessoa.h"

int main(){
    int qtd = 0, i = 0;
    scanf("%d", &qtd);
    tPessoa pessoas[qtd];

    for(i = 0; i < qtd; i++){
        scanf("%*[^a-zA-Z]");
        pessoas[i] = CriaPessoa();
        LePessoa(pessoas+i);
    }
    
    AssociaFamiliasGruposPessoas(pessoas, qtd);

    for(i = 0;i < qtd; i++){
        ImprimePessoa(pessoas+i);
    }


    return 0;
}