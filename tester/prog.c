#include <stdio.h>

void levetor(int qtd, int * vet);
void imprime(int qtd, int * vet);
void ordenaVetor(int qtd, int * vet);

int main(){

    int qtd = 0;
    scanf("%d", &qtd);
    int vet[qtd];
    int i = 0;
    levetor(qtd, vet);

    imprime(qtd, vet);
    ordenaVetor(qtd, vet);
    imprime(qtd, vet);

    return 0;
}

void levetor(int qtd, int * vet){
    int i = 0;
    for(i = 0; i < qtd; i++){
        scanf("%d", &vet[i]);
    }
    return;
}
void imprime(int qtd, int * vet){
    int i = 0;
    printf("esse eh o vetor:\n");
    for(i = 0; i < qtd; i++){
        printf("%d ", vet[i]);
    }
    return;
}

void ordenaVetor(int qtd, int * vet){

    int i = 0, j = 0, maior = 0, idx = 0;
    for(i = 0; i < qtd-1; i++){
    
        maior = vet[i+1];
        idx = i+1;

        for(j = i+1; j < qtd; j++){
            if(maior<vet[j]){
                maior = vet[j];
                idx = j;
            }
        }
        if(maior>vet[i]){
            int aux;
            aux = vet[i];
            vet[i] = vet[idx];
            vet[idx] = aux;
        }
    }
}
