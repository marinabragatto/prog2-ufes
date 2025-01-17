#include <stdio.h>

void levetor(int qtd, int * vet);
void imprime(int qtd, int * vet);
void ordenaVetor(int qtd, int * vet);
int buscaMaiorEntreAeB(int * vet, int i, int qtd);

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
    int idx = 0;
    for(i = 0; i < qtd - 1; i++){

        idx = buscaMaiorEntreAeB(vet, i+1, qtd);

        if(vet[idx]>vet[i]){
            int aux;
            aux = vet[i];
            vet[i] = vet[idx];
            vet[idx] = aux;
        }
    }
}

int buscaMaiorEntreAeB(int * vet, int i, int qtd){
    int maior, idx;
    maior = vet[i];
    idx = i;
    int j = 0;

    for (j = 0; j < qtd; j++){
        if(maior < vet[j]){
            maior = vet[j];
            idx = j;
        }

    }
    return j;
}

/*for(i = 0; i < qtd - 1 ; i++){
        menor = vet[i+1];
        idxMenor = i+1;
        for(j = i+2; j < qtd; j++){
            if(vet[j] < menor){
                menor = vet[j];
                idxMenor = j;
            }
        }
        if(menor < vet[i]){
            aux = vet[i];
            vet[i] = menor;
            vet[idxMenor] = aux;
        }
    }
    return;*/