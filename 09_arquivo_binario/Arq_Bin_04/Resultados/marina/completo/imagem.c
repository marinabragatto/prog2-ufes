#include "imagem.h"
#include <stdlib.h>
#include <stdio.h>
//typedef enum {
//    FLOAT = 0, 
//    INT = 1    
//} Tipo;

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem {
    Tipo tipo;
    int largura;
    int altura;
    void * dados;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho){
    Imagem * imagem;
    imagem = (Imagem*)malloc(sizeof(Imagem));

    FILE * arq;
    arq = fopen(caminho, "rb");
    if(arq == NULL){
        printf("erro ao abrir arquivo");
        exit(1);
    }

   
    fread(&imagem->altura, sizeof(int), 1, arq); // linha
    fread(&imagem->largura, sizeof(int), 1, arq); // colunas
    fread(&imagem->tipo, sizeof(Tipo), 1, arq);
    

    if(imagem->tipo == FLOAT){
        imagem->dados = (float*)malloc(sizeof(float)*(imagem->altura*imagem->largura));

        for(int i = 0; i < (imagem->largura)*(imagem->altura); i++){
            fread(&((float*)imagem->dados)[i], sizeof(float), 1, arq);
        }
    }
    else if(imagem->tipo == INT){
        imagem->dados = (int*)malloc(sizeof(int)*(imagem->altura*imagem->largura));

        for(int i = 0; i < (imagem->largura)*(imagem->altura); i++){
            fread(&((int*)imagem->dados)[i], sizeof(int), 1, arq);
        }
    }
    

    fclose(arq);
    return imagem;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img){
    if(img){
        
        if(img->dados){
            free(img->dados);
        }

        free(img);
    }
}

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img A imagem.
 * @return A altura da imagem.
 */
int ObterAlturaImagem(Imagem *img){
    return img->altura;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img A imagem.
 * @return A largura da imagem.
 */
int ObterLarguraImagem(Imagem *img){
    return img->largura;
}

/**
 * @brief Função para obter o tipo de uma imagem.
 * @param img A imagem.
 * @return O tipo da imagem.
 */
Tipo ObterTipoImagem(Imagem *img){
    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * @param img A imagem.
 * @return Um ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img){
    return img->dados;
}