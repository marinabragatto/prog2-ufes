#include <stdio.h>
#include "empresa.h"
#include "funcionario.h"

int main(){
    int qtdEmpresas = 0, idEmpresa = 0 ;

    scanf("%d", &qtdEmpresas);
    tEmpresa emp[qtdEmpresas];
    int i = 0, aux = qtdEmpresas;

    while(aux){      
        emp[i] = leEmpresa();
        //printf("\n");
        aux--;
        i++;
    }

    aux = qtdEmpresas;
    i = 0;
    
    while(aux){      
        imprimeEmpresa(emp[i]);
        //printf("\n");
        aux--;
        i++;
    }

 
    return 0;
}