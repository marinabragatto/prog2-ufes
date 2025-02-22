#include "tDepartamento.h"
#include <string.h>


//typedef struct departamento {
//    char curso1[STRING_MAX];
//    char curso2[STRING_MAX];
//    char curso3[STRING_MAX];
//    char diretor[STRING_MAX];
//    char nome[STRING_MAX];
 //   int m1, m2, m3;
//} tDepartamento;

/**
 * @brief Cria um departamento com os dados passados via parâmetro
 *
 *
 * @param *curso1 Ponteiro para string que contém o nome do primeiro curso do departamento
 * @param *curso2 Ponteiro para string que contém o nome do segundo curso do departamento
 * @param *curso3 Ponteiro para string que contém o nome do terceiro curso do departamento
 * @param *nome Ponteiro para string que contém o nome do departamento
 * @param m1 Nota do primeiro curso (curso1)
 * @param m2 Nota do segundo curso (curso2)
 * @param m3 Nota do terceiro curso (curso3)
 * @param *diretor Ponteiro para string que contém o nome do diretor/chefe do departamento
 */
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

/**
 * @brief Imprime os atributos de um departamento em tela
 *
 * @param depto - Um departamento que terá seus dados impressos em tela
 */

void ImprimeAtributosDepartamento(tDepartamento depto){
    float media;
    media = (depto.m1 + depto.m2 + depto.m3)/3.0;
    
    printf("\nDepartamento: %s\n\tDiretor: %s\n\t1o curso: %s\n\tMedia do 1o curso: %d\n\t2o curso: %s\n\tMedia do 2o curso: %d\n\t3o curso: %s\n\tMedia do 3o curso: %d\n\tMedia dos cursos:%.2f", depto.nome, depto.diretor, depto.curso1, depto.m1, depto.curso2, depto.m2, depto.curso3, depto.m3, media);
}

/**
 * @brief Ordena os departamentos de acordo com as médias das notas de cada um dos seus três cursos (da maior para a menor).
 *
 * @param *vetor_deptos - Ponteiro para um vetor de departamentos
 * @param num_deptos - O número de departamentos contidos no vetor_deptos
 */
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

// vc primeiro tem um vetor grande ai vc pega a posicao 1 e vai buscar a menor dali p frente 
}