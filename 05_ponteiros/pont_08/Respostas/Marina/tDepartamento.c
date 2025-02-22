#include "tDepartamento.h"
#include <string.h>

tDepartamento CriaDepartamento(char *curso1, char *curso2, char *curso3, char *nome, int m1, int m2, int m3, char *diretor){
    tDepartamento depart;

    strcpy(depart.curso1, curso1);
    strcpy(depart.curso2, curso2);
    strcpy(depart.curso3, curso3); 
    strcpy(depart.diretor, diretor);
    strcpy(depart.nome, nome);
    depart.m1 = m1;
    depart.m2 = m2;
    depart.m3 = m3;
    return depart;
}


void ImprimeAtributosDepartamento(tDepartamento depto){
    float media;
    media = (depto.m1 + depto.m2 + depto.m3)/3.0;
    
    printf("\nDepartamento: %s\n\tDiretor: %s\n\t1o curso: %s\n\tMedia do 1o curso: %d\n\t2o curso: %s\n\tMedia do 2o curso: %d\n\t3o curso: %s\n\tMedia do 3o curso: %d\n\tMedia dos cursos:%.2f", depto.nome, depto.diretor, depto.curso1, depto.m1, depto.curso2, depto.m2, depto.curso3, depto.m3, media);
}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    int vet_media[num_deptos];
    int i = 0;
    
    for(i = 0 ; i < num_deptos; i++){
        vet_media[i] = vetor_deptos[i].m1 + vetor_deptos[i].m2 + vetor_deptos[i].m3;   
    }

    int idx = 0, j = 0, maior = 0;
    
    for(i = 0; i < num_deptos - 1; i++){
        maior = (vet_media[i+1]);
        idx = i+1;
        for(j = i+1; j < num_deptos; j++){
            if(vet_media[j] > maior){
                maior = vet_media[j];
                idx = j;
            }
        }
        if(maior > vet_media[i]){
            tDepartamento aux;
            int aux2;
            aux2 = vet_media[i];
            vet_media[i] = vet_media[idx];
            vet_media[idx] = aux2;
            aux = vetor_deptos[i];
            vetor_deptos[i] = vetor_deptos[idx];
            vetor_deptos[idx] = aux;
        }
    }
    return;
}