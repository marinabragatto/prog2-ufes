#include "tadgen.h"

//typedef enum {
//    FLOAT = 0,
//    INT = 1
//} Type;

//typedef struct generic tGeneric;

struct generic{
    void * vetor;
    int tamanho;
    Type type;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric * generico;

    generico = (tGeneric*)malloc(sizeof(tGeneric));
    generico->tamanho = numElem;
    generico->type = type;

    if(type == FLOAT){
        generico->vetor = (float*)malloc(sizeof(float)*numElem);
    }

    if(type == INT){
        generico->vetor = (int*)malloc(sizeof(int)*numElem);
    }

    return generico;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    if(gen){
        if(gen->vetor){
            free(gen->vetor);
        }
        free(gen);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){

    printf("\nDigite o vetor:\n");
    
    int i = 0;
    for(i = 0; i < gen->tamanho; i++){
        if(gen->type == FLOAT){
            scanf("%f", &((float*)gen->vetor)[i]);
        }
        if(gen->type == INT){
            scanf("%d", &((int*)gen->vetor)[i]);
        } 
    }
    
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    int i = 0;
    for(i = 0; i < gen->tamanho; i++){
         if(gen->type == FLOAT){
            printf("%.2f ", ((float*)gen->vetor)[i]);
        }
        if(gen->type == INT){
            printf("%d ", ((int*)gen->vetor)[i]);
        }
        
    }
    printf("\n");
}
