#include "utils_char2.h"
#include <stdlib.h>

int EhMultiploDez(int numero){
    if(((numero%10) == 0) && numero != 0){
        return 1;
    }
    else {
        return 0;
    }
}

void InicializaVetor(char * vetor){
    int i = 0;
    for (i = 0; i < TAM_PADRAO; i++){
        vetor[i] = '_';
    }
    vetor[i]= '\0';
    return;
}

char *CriaVetorTamPadrao(){
    char *vetor;
    vetor = (char*)malloc((sizeof(char))*(TAM_PADRAO+1));
    if(vetor == NULL){
        printf("!!!erro de alocacao!!!\n");
        exit(1);
    }
    InicializaVetor(vetor);
    return vetor;
}

char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo){
    vetor = (char*)realloc(vetor, sizeof(char)*(tamanhoantigo+11));
    InicializaVetor(vetor+tamanhoantigo);
    return vetor;
}

char* LeVetor(char *vetor, int *tamanho){
    int i = 0;
    char letra = 'a';
    for(i = 0; 1; i++){
        scanf("%c", &letra);
        if(letra != '\n'){
            if(EhMultiploDez(i)){
                vetor = AumentaTamanhoVetor(vetor, *tamanho);
                *tamanho+= 10; 
            }
            vetor[i] = letra;
        }
        else {
            break;
        }
    }
    return vetor;
}

void ImprimeString(char *vetor){
    printf("%s\n", vetor);
}

void LiberaVetor(char *vetor){
    if(vetor != NULL){
        free(vetor);
    }
    else{
        //exit(1)
    }
}
    
