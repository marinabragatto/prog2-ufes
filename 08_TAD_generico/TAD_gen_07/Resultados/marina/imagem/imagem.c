#include "imagem.h"
#include <stdlib.h>
/**
 * @brief Enumeração para representar o tipo de dados da imagem.
 */
//typedef enum {
//    FLOAT = 0, 
//    INT = 1    
//} Tipo;

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem {
    int altura;
    int largura;
    Tipo tipo;
   void * matriz;
   //float * matrizFloat;
   //int * matrizInt;

};

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Altura da imagem.
 */
int ObterAltura(Imagem *img){
    return img->altura;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Largura da imagem.
 */
int ObterLargura(Imagem *img){
    return img->largura;
}

/**
 * @brief Função para obter o tipo de dados de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Tipo de dados da imagem.
 */
Tipo ObterTipoImagem(Imagem *img){
    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma linear (vetor).
 * @param img Ponteiro para a imagem.
 * @return Ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img){
   // return NULL;
   //if(img->tipo == int)
    return img->matriz;
}

/**
 * @brief Função para criar uma imagem.
 * @param altura Altura da imagem.
 * @param largura Largura da imagem.
 * @param tipo Tipo de dados da imagem.
 * @return Ponteiro para a imagem criada. Caso não seja possível criar a imagem, o programa é encerrado.
 */
Imagem *CriarImagem(int altura, int largura, Tipo tipo){
    Imagem * imagem;
    int i = 0;
    imagem  = (Imagem*)malloc(sizeof(Imagem));

    imagem->altura = altura;
    imagem->largura = largura;
    imagem->tipo = tipo;
    if(tipo == INT){
        imagem->matriz = (int*)malloc(sizeof(int)*(altura*largura));
    }
    if(tipo == FLOAT){
        imagem->matriz = (float*)malloc(sizeof(float)*(altura*largura));
    }

   // imagem->matriz = (void**)malloc(sizeof(void*)*(altura*largura));
   // for(i = 0 ; i < (altura*largura); i++){
   //     imagem->matriz[i] = NULL;
   // }

    return imagem;
}

/**
 * @brief Função para ler uma imagem, primeiro lendo a altura, largura e tipo de dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da imagem.
 * @return Ponteiro para a imagem lida. (Crie a imagem com a função CriarImagem).
 */
Imagem *LerImagem(){
    //printf("oiii");
    Imagem * imagem = NULL;
    
    int largura = 0, altura = 0, tipo = 0, i = 0, j = 0;
    
    scanf("%d %d %d\n", &altura, &largura, &tipo);
    //printf("%d %d %d", largura, altura, tipo);

    
    if(tipo == 0){
        float num;
        void * elem;
        imagem = CriarImagem(altura, largura, FLOAT);
        for(i = 0; i < (imagem->altura*imagem->largura); i ++){
                scanf("%f", &num);
                //elem = (float*)malloc(sizeof(float));
                //*(float*)elem = num;
               (((float*)imagem->matriz)[i]) = num;
        }
    }
    else if(tipo == 1){
        int num;
        void * elem;
        imagem = CriarImagem(altura, largura, INT);
        for(i = 0; i < (imagem->altura*imagem->largura); i++){
                scanf("%d", &num);
               (((int*)imagem->matriz)[i]) = num;
        }
    }
    
    return imagem;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void ImprimirImagem(Imagem *img){

}

/**
 * @brief Função para destruir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void DestruirImagem(Imagem *img){
    if(img){
        if(img->matriz){
            int i = 0;
            free(img->matriz);
        }
        free(img);
    }
}