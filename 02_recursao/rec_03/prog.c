#include <stdio.h>

void leVet(int vet[], int tamVet);
int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado); 

int main(){
    int qtd = 0, tamVet = 0, i = 0, proc = 0;

    scanf("%d",&qtd);
    for(i = 0; i < qtd; i++){
        scanf("%d", &proc);
        scanf("%d", &tamVet);
        int vet[100];
        leVet(vet, tamVet);
        printf("%d", ContaOcorrencias(vet, tamVet, proc));
        printf("\n");
        
    }

    return 0;
}

void leVet(int vet[], int tamVet){
    int i = 0;
    for(i = 0; i < tamVet; i++){
        scanf("%d", &vet[i]);
    }
    return;
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado){
    if(numElementos == 0){
        return 0;
    }
    else if(vet[0] == numeroProcurado){
        return 1 + ContaOcorrencias(vet+1, numElementos - 1, numeroProcurado);
    }
    else{
        return ContaOcorrencias(vet+1, numElementos - 1, numeroProcurado);
    }
} 