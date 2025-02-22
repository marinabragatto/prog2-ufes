#include <stdio.h>
#include "tadgen.h"

int main(){
    int tipo = 0, tam = 0;
    printf("tad_gen_01\nDigite o tipo e numero de elementos: ");
    scanf("%d %d\n", &tipo, &tam);
    tGeneric * generico;
    Type type;
    if(tipo == 1){
        type = INT;
    }
    else if(tipo == 0){
        type =  FLOAT;
    }
    
    generico = CriaGenerico(type,tam);
    LeGenerico(generico);
    ImprimeGenerico(generico);
    DestroiGenerico(generico);


    return 0;
}