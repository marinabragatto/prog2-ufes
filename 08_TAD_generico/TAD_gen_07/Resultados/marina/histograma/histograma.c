#include "histograma.h"
#include <stdlib.h>

/**
 * @brief Estrutura para representar um Histograma.
 */
struct tHistograma {
    int * numPixIntervalor;
    int numIntervalos; 
    int tamIntervalo;
};

/**
 * @brief Função para calcular o histograma de uma imagem.
 * @param img Ponteiro para a imagem.
 * @param nIntervalos Número de intervalos no histograma.
 * @return Ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos){
    Histograma * hist;
    hist = (Histograma*)malloc(sizeof(Histograma));

    hist->numIntervalos = nIntervalos;

    void * dados;
    int i = 0;

    dados = ObterDadosImagem(img);

    
    int tamanhoIntervalo;
    int intervalo;
    
    hist->numPixIntervalor = (int*)malloc(sizeof(int)*nIntervalos);
    for(i = 0; i < nIntervalos; i++){
        hist->numPixIntervalor[i] = 0;
    }

    tamanhoIntervalo = 256/nIntervalos;
    int resto;
    resto = 256%nIntervalos;
    hist->tamIntervalo = tamanhoIntervalo;
    if(resto != 0){
        hist->tamIntervalo++;
        tamanhoIntervalo++;
    }

    for(i = 0; i < ObterAltura(img)*ObterLargura(img); i++){

        for(int j = 0, intervalo = tamanhoIntervalo; j < nIntervalos; j++, intervalo+=tamanhoIntervalo){
            int minimo = intervalo - tamanhoIntervalo;
            if(ObterTipoImagem(img) == FLOAT){
                int num;

                num = (int)(((float*)dados)[i]*255);
                if(num >= minimo && num < intervalo ){
                    hist->numPixIntervalor[j]++;
                }
            }
            if(ObterTipoImagem(img) == INT){
                if(((int*)dados)[i] >= minimo && ((int*)dados)[i] < intervalo ){
                    hist->numPixIntervalor[j]++;
                }
            }
        }
        
    }
    return hist;
        
}

/**
 * @brief Função para imprimir um histograma na tela.
 * @param histograma Ponteiro para o histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma){
    int i = 0, intervalo = 0, minimo = 0;
    for(i = 0, intervalo = histograma->tamIntervalo; i < histograma->numIntervalos;i++,intervalo += histograma->tamIntervalo ){
        minimo = intervalo - histograma->tamIntervalo;
        printf("[%d, %d): %d\n", minimo, intervalo, histograma->numPixIntervalor[i]);
    }


}

/**
 * @brief Função para destruir um histograma.
 * @param histograma Ponteiro para o histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma){
    if(histograma){
        if(histograma->numPixIntervalor){
            free(histograma->numPixIntervalor);
        }
        free(histograma);
    }
}