#include "departamento.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//#define STRING_MAX 101 // número máximo de caracteres por string

//typedef struct Departamento {
//    char *nome;     // nome do departamento
//    char *c1, *c2, *c3;    // nomes dos cursos do departamento
//    int m1, m2, m3;     // médias de notas dos cursos do departamento
//    char *diretor;    // nome do diretor do departamento
  //  float media_geral;
//} tDepartamento;

/**
 * @brief Cria uma estrutura, alocada dinamicamente, que possui os campos de um departamento. 
 * Lembre-se de inicializar os ponteiros com NULL e as variáveis númericas com -1.
 * 
 * @return Um ponteiro para uma estrutura de um Departamento.
 */
tDepartamento* CriaDepartamento(){
    tDepartamento *departamento;
    departamento = (tDepartamento*)malloc(sizeof(tDepartamento));

    departamento->c1 = NULL;
    departamento->c2 = NULL;
    departamento->c3 = NULL;
    
    departamento->diretor = NULL;
    
    departamento->nome = NULL;
    
    departamento->m1 = -1;
    departamento->m2 = -1;
    departamento->m3 = -1;
    
    departamento->media_geral = -1;

    return departamento;

}

/**
 * @brief Preenche os dados de uma estrutura departamento a partir de valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param c1 Nome de um dos cursos do departamento.
 * @param c2 Nome de um dos cursos do departamento.
 * @param c3 Nome de um dos cursos do departamento.
 * @param nome Nome do departamento.
 * @param m1 Média do curso c1.
 * @param m2 Média do curso c2.
 * @param m3 Média do curso c3.
 * @param diretor Nome do diretor.
 */
void PreencheDadosDepartamento(tDepartamento* depto, char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){
    if((depto->c1 == NULL)){
        int tamanho = 0;
        tamanho = strlen(c1);
        depto->c1 = (char*)malloc(sizeof(char)*(tamanho+1));
        
        tamanho = strlen(c2);
        depto->c2 = (char*)malloc(sizeof(char)*(tamanho+1));        

        tamanho = strlen(c3);
        depto->c3 = (char*)malloc(sizeof(char)*(tamanho+1));
        

        tamanho = strlen(nome);
        depto->nome = (char*)malloc(sizeof(char)*(tamanho+1));
        

        tamanho = strlen(diretor);
        depto->diretor = (char*)malloc(sizeof(char)*(tamanho+1));
        
        strcpy(depto->c1, c1);

        strcpy(depto->c2,c2);
        
        strcpy(depto->c3, c3);

        strcpy(depto->nome, nome);

        strcpy(depto->diretor, diretor);
        
        //strcpy(depto->c1, c1);

        //depto->c2 = (char*)malloc(sizeof(char)*(STRING_MAX+1));
        //strcpy(depto->c2,c2);
        
        //depto->c3 = (char*)malloc(sizeof(char)*(STRING_MAX+1));
        //strcpy(depto->c3, c3);

        //depto->nome = (char*)malloc(sizeof(char)*(STRING_MAX+1));
        //strcpy(depto->nome, nome);
        
        //depto->diretor = (char*)malloc(sizeof(char)*(STRING_MAX+1));
        //strcpy(depto->diretor, diretor);
    }
    else{ 
        
        depto->c1 = c1;
        depto->c2 = c2;
        depto->c3 = c3;
        depto->nome = nome;
        depto->diretor = diretor;
    }


    depto->m1 = m1;
    depto->m2 = m2;
    depto->m3 = m3;

    depto->media_geral = CalculaMediaGeralDepartamento(depto);

    return depto;
}

void LiberaMemoriaDepartamento(tDepartamento* depto){
    if(depto){
        if(depto->c1){
            free(depto->c1);
        }
        else{
            printf("tentou liberar vetor nulo\n");
        }

        if(depto->c2){
            free(depto->c2);
        }
        else{
            printf("tentou liberar vetor nulo\n");
        }
        
        if(depto->c3){
            free(depto->c3);
        }
        else{
            printf("tentou liberar vetor nulo\n");
        }

        if(depto->diretor){
            free(depto->diretor);
        }
        else{
            printf("tentou liberar vetor nulo\n");
        }
        
        if(depto->nome){
            free(depto->nome);
        }
        else{
            printf("tentou liberar vetor nulo\n");
        }

        free(depto);
    }
    else{
        printf("tentou liberar vetor nulo\n");
    }
}


/**
 * @brief Imprime os atributos do departamento, sendo eles: cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param depto Departamento cujos atributos serão impressos.
 */
void ImprimeAtributosDepartamento (tDepartamento* depto){
    //
    float desvio = 0;
    desvio = CalculaDesvioPadraoDepartamento(depto);
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\ndiretor => %s\ncurso1 => %s, media1 => %d\ncurso2 => %s, media2 => %d\ncurso3 => %s, media3 => %d\nmedia geral => %.2f\ndesvio padrao => %.2f\n\n", depto->nome, depto->diretor, depto->c1, depto->m1, depto->c2, depto->m2, depto->c3, depto->m3, depto->media_geral, desvio);
    

}

/**
 * @brief Verifica se a media inserida é valida, ou seja, pertence à [0, 10].
 * 
 * @param media Valor a ser validado.
 * @return int Se é válida (1) ou não (0).
 */
int ValidaMediaDepartamento (int media){
    if(media >= 0 && media <= 10){
        return 1;
    }
    else{
        return 0;
    }
}

/**
 * @brief Calcula o Desvio Padrão das médias por curso de um departamento.
 * 
 * @param depto Departamento cujo Desvio Padrão de médias por curso deve ser calculado.
 * @return double Valor do cálculo do Desvio Padrão.
 */
double CalculaDesvioPadraoDepartamento(tDepartamento* depto){
    float somatorio = 0, desvio = 0;
    somatorio = pow(depto->media_geral - depto->m1, 2) +  pow(depto->media_geral - depto->m2, 2) + pow(depto->media_geral - depto->m3,2);
    somatorio = somatorio/3;
    desvio = sqrt(somatorio);
    return desvio;
}

/**
 * @brief Calcula a média simples das notas dos cursos do departamento.
 * 
 * @param depto Departamento cuja media simples deve ser calculada.
 * @return double Valor do calculo da média simples.
 */
double CalculaMediaGeralDepartamento(tDepartamento* depto){
    float somatorio = 0;
    somatorio = depto->m1 + depto->m2 + depto->m3;
    return somatorio/3;
}

/**
 * @brief Ordena o vetor de departamentos em ordem decrescente de acordo com as médias dos departamentos.
 * 
 * @param deptos Vetor de departamentos a ser ordenado.
 * @param tamanho Tamanho do vetor a ser ordenado.
 */
void OrdenaPorMediaDepartamentos(tDepartamento* d[], int tamanho){
    int idxMaior = 0;
    tDepartamento *deptoMaior;
    int i = 0, j = 0;

    for(i = 0; i < tamanho - 1; i++){
        idxMaior = i;
        deptoMaior = d[i];
        for(j = i +1 ; j < tamanho; j++){
            if(deptoMaior->media_geral < d[j]->media_geral){
                idxMaior = j;
                deptoMaior = d[j];
            }
        }
        if(d[i]->media_geral < deptoMaior->media_geral){
            tDepartamento *deptAux;
            deptAux = d[idxMaior];
            d[idxMaior] = d[i];
            d[i] = deptAux; 
        }
    }

}
