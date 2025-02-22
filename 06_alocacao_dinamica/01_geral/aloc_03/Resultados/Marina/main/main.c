#include "utils_char.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int qtd = 0;
    scanf("%d", &qtd);
    scanf("%*[^a-zA-Z0-9]");
    char *vet;
    vet = CriaVetor(qtd);
    ImprimeString(vet, qtd);
    LeVetor(vet, qtd);
    ImprimeString(vet,qtd);
    LiberaVetor(vet);
    return 0;
}