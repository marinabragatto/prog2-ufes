#include <stdio.h>

void LeVet(int vet[], int qtdVet);
void imprimeVet(int vet[], int qtdVet);
int SomaElementosPares(int* vet, int numElementos);

int main(){
    int i = 0, qtd = 0; 
    int qtdVet = 0;

    scanf("%d", &qtd);

    for(i = 0; i < qtd; i++){
        int vet[100];
        scanf("%d", &qtdVet);
        LeVet(vet, qtdVet);
        printf("%d\n", SomaElementosPares(vet, qtdVet));
    }
    
    return 0;
}

int SomaElementosPares(int* vet, int numElementos){
    
    if(numElementos == 0){
        return 0;
    }
    else if(vet[0] % 2 == 0){
        return SomaElementosPares(vet+1, numElementos - 1) + vet[0]; 
    }
    else {
        return SomaElementosPares(vet+1, numElementos - 1); 
    }
}

void LeVet(int vet[], int qtdVet){
    int i = 0;

    for(i = 0; i < qtdVet; i++){
        scanf("%d", &vet[i]);
    }
    return;
}

void imprimeVet(int vet[], int qtdVet){
    int i = 0;
    printf("\n");
    for(i = 0; i < qtdVet; i++){
        printf("%d ", vet[i]);
    }
    return;
}

/**/