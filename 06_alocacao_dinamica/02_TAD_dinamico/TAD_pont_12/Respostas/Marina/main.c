#include <stdio.h>
#include "array.h"

int main(){
    Array *array;
    array = CriarArray();
    LerArray(array);
    OrdenarArray(array);
    int numeroBuscado = 0, idx = 0;

    scanf("%d", &numeroBuscado);
    idx = BuscaBinariaArray(array,numeroBuscado); 
    if(idx != -1){
        printf("Elemento %d encontrado no índice %d.\n", numeroBuscado, idx);
    }
    else{
        printf("Elemento %d não encontrado no array (%d).\n", numeroBuscado, idx);
    }
    DestruirArray(array);
    return 0;
}