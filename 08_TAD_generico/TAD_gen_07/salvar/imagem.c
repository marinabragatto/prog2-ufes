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
   // void *** matriz;
   void ** matriz;
    //void * matriz;

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

    imagem->matriz = (void**)malloc(sizeof(void*)*(altura*largura));
    for(i = 0 ; i < altura*largura; i++){
        imagem->matriz[i] = NULL;
    }

    //imagem->matriz = (void***)malloc(sizeof(void**)*altura);
    
  //  for(i = 0; i < altura; i++){
    //    imagem->matriz[i] = (void**)malloc(sizeof(void*)*largura);
   // }

   // int j = 0;

   // for(i = 0; i < altura; i++){
    //    for(j = 0; j < largura; j++){
    //        imagem->matriz[i][j] = NULL;
      //  }
   // }
   // imagem->matriz = (void***)malloc(sizeof(void**)*altura);
    return imagem;
}

/**
 * @brief Função para ler uma imagem, primeiro lendo a altura, largura e tipo de dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da imagem.
 * @return Ponteiro para a imagem lida. (Crie a imagem com a função CriarImagem).
 */
Imagem *LerImagem(){
    printf("oiii");
    Imagem * imagem = NULL;
    
    int largura = 0, altura = 0, tipo = 0, i = 0, j = 0;
    
    scanf("%d %d %d\n", &altura, &largura, &tipo);
    printf("%d %d %d", largura, altura, tipo);

    
    if(tipo == FLOAT){
        float num;
        void * elem;
        imagem = CriarImagem(altura, largura, FLOAT);
        for(i = 0; i < (imagem->altura*imagem->largura); i ++){
            //for(j= 0; j < imagem->largura; j++){
                scanf("%f", &num);
               // printf("%f \n", num);
                elem = (float*)malloc(sizeof(float));
                *(float*)elem = num;
                imagem->matriz[i] = elem;
                //imagem->matriz[i][j] = elem;
            //}
        }
    }
    else if(tipo == INT){
        int num;
        void * elem;

        imagem = CriarImagem(altura, largura, INT);
        
        for(i = 0; i < (imagem->altura*imagem->largura); i ++){
           // for(j= 0; j < imagem->largura; j++){
                scanf("%d", &num);
                elem = (int*)malloc(sizeof(int));
                *(int*)elem = num;
                imagem->matriz[i] = elem;
                //imagem->matriz[i][j] = elem;
           // }
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
            int i = 0, j = 0;
          /*  for(i = 0; i < img->altura; i++){
                for(j = 0; j< img->largura; j++){
                    if(img->matriz[i][j]){
                        free(img->matriz[i][j]);
                    }
                }
            }

            for(i = 0 ; i < img->altura; i++){
                if(img->matriz[i]){
                    free(img->matriz[i]);
                }
                
            }*/
           for(i = 0; i < img->altura*img->largura; i++){
                if(img->matriz[i]){
                    free(img->matriz[i]);
                }
           }
            free(img->matriz);
        }
        free(img);
    }
}