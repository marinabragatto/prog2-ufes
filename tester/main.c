#include <stdio.h>

void OrdenaDepartamentosPorMedia(int *vetor_deptos, int num_deptos);

int main(){
    int qtd;
    scanf("%d", &qtd);
    int vet[qtd], i = 0;
    printf("antes\n;");
    for(i = 0; i < qtd; i++){
        scanf("%d", &vet[i]);
    }

    for(i = 0; i < qtd; i++){
        printf("%d ", vet[i]);
    }
    OrdenaDepartamentosPorMedia(vet, qtd);
    printf("\ndps\n");
    for(i = 0; i < qtd; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}

void OrdenaDepartamentosPorMedia(int *vetor_deptos, int num_deptos){
    
    int i = 0;


    int idx = 0, j = 0, maior = 0;
    
    for(i = 0; i < num_deptos-1; i++){
    
        maior = vetor_deptos[i+1];
        idx = i+1;

        for(j = i+1; j < num_deptos; j++){
            if(vetor_deptos[j] > maior){
                maior = vetor_deptos[j];
                idx = j;
            }
        }
        
        if(maior > vetor_deptos[i]){
            int aux;
            aux = vetor_deptos[i];
            vetor_deptos[i] = vetor_deptos[idx];
            vetor_deptos[idx] = aux;
        }
    }

// vc primeiro tem um vetor grande ai vc pega a posicao 1 e vai buscar a menor dali p frente 
}