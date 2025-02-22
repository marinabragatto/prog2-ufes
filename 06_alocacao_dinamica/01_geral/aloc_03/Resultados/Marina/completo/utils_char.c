#include "utils_char.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * Cria um vetor de caracteres de tamanho especificado, alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas posições com "_"
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @param tamanho Tamanho do vetor a ser criado.
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetor(int tamanho){
    int i = 0;
    char *vet;

    vet = malloc(sizeof(char)*(tamanho + 2));
    
    if(vet){
        for (i = 0; i < tamanho; i++)
        {
            *(vet+i) = '_'; 
        }
        *(vet+i) = '\n';
        i++;
        *(vet+i) = '\0';
    }
    else{
        printf("ERRO DE ALOCACAO!\n");
    }
    
    
    return vet;
}

/**
 * Lê uma string do tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
*/
void LeVetor(char *vetor, int tamanho){
    int i = 0, len = 0;
    scanf("%*[^a-zA-Z0-9]");
    fgets(vetor, tamanho + 2, stdin);
    len = strlen(vetor);
    *(vetor+len-1) = '_';//repoe o que \n tirou
    
    
    
    if(len < tamanho){
        *(vetor+len) = '_'; //repoe o que o \0 tirou
        *(vetor+tamanho) = '\0';
        
    }
    else{
        *(vetor+tamanho) = '\0';
    }
    
    
    //i++;
    //*(vet+i) = '\0';
    return;
}

/**
 * Imprime a string
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
*/
void ImprimeString(char *vetor, int tamanho){
    printf("%s", vetor);
}

/**
 * Libera a memória alocada para um vetor de caracteres.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(char *vetor){
    if(vetor){
        free(vetor);
    }
    return;
}


 //printf("%%");
   // scanf("%[^\n]" ,vetor);

    //for (i = 0; i < tamanho; i++){
            //*(vet+i) = '_';
            //scanf("%d", (vetor+i)); 
    //}
