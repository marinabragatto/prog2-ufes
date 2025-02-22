#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(){
    int l = 0, c = 0;
    scanf("%d %d", &l, &c);
    int **matriz;
    matriz = CriaMatriz(l,c);
    LeMatriz(matriz, l, c);
    ImprimeMatrizTransposta(matriz, l ,c);
    LiberaMatriz(matriz, l);

    return 0;


}