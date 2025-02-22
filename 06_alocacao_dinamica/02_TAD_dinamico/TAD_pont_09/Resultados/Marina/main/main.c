#include <stdio.h>
#include "empresa.h"

int main(){
    int qtd = 0, i = 0;
    scanf("%d", &qtd);

    tEmpresa *empresa[qtd];
    for(i = 0; i < qtd; i++){
        empresa[i] = CriaEmpresa();
        LeEmpresa(empresa[i]);
    }

    for(i = 0; i < qtd;i ++){    
        ImprimeEmpresa(empresa[i]);
        ApagaEmpresa(empresa[i]);
    }

    return 0 ;
}