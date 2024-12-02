#include <stdio.h>

void ordeneCrescente(int *vet, int tam);
void imprimeDadosVetor(int *vet, int tam);
void leDadosParaVetor(int *vet, int tam);

int main(){
    int casos; scanf("%d", &casos);
    while(casos){
        int tam; 
        scanf("%d", &tam);

        int vet[tam];
        leDadosParaVetor(vet, tam);
        imprimeDadosVetor(vet, tam);
        ordeneCrescente(vet, tam);
        imprimeDadosVetor(vet, tam);
        casos--;
    }
    return 0;
}

void leDadosParaVetor(int *vet, int tam){
    int i = 0;
    for(i = 0; i < tam; i++){
        scanf("%d", vet+i);
    }
    return;
}

void imprimeDadosVetor(int *vet, int tam){
    int i = 0;
    for(i = 0; i < tam; i++){
        printf("%d ", *(vet+i));
    }
    return;
}

void ordeneCrescente(int *vet, int tam){
    int idxMenor = 0;
    int menor = *vet;
    int j = 0, i = 0;

    for(i = 0; i < tam - 1; i++){
        idxMenor = i;
        menor = *(vet + i);
        for(j = i; j < tam; j++){
            if(menor > *(vet+j)){
                menor = *(vet+j);
                idxMenor = j;
            }
        }
        if(*(vet+i) > *(vet+idxMenor)){
            int aux;
            aux = *(vet+i);
            *(vet+i) = *(vet+idxMenor);
            *(vet+idxMenor) = aux;
        }
    }
    return;

}