#include <stdio.h>
#include "utils.h"

int main(){
    int tamanho=0;
    scanf("%d", &tamanho);
    int *ptr;
    ptr = CriaVetor(tamanho);
    LeVetor(ptr, tamanho);
    float media  = 0;
    media = CalculaMedia(ptr, tamanho);
    printf("%.2f\n", media);
    LiberaVetor(ptr);
    return 0;
}