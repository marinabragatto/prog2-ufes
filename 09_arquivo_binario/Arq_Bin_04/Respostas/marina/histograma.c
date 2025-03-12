#include "histograma.h"


struct tHistograma {
    int numeroInt;
    int tamanhoIntervalo;
    int * intervalos;
};

/**
 * @brief Função para calcular um histograma a partir de uma imagem.
 * @param image A imagem para calcular o histograma.
 * @param n_buckets O número de intervalos no histograma.
 * @return Um ponteiro para o histograma calculado.
 */

 void inicializaIntervalos(int * intervalos, int num){
    for(int i = 0; i < num; i++){
        intervalos[i] = 0;
    }
 }

Histograma *CalcularHistograma(Imagem *img, int nIntervalos){
    Histograma * hist;
    hist = (Histograma*)malloc(sizeof(Histograma));
    hist->intervalos = (int*)malloc(sizeof(int)*nIntervalos);
    hist->numeroInt = nIntervalos;
    inicializaIntervalos(hist->intervalos,nIntervalos);

    int resto = 0, tamInt = 0;
    
    tamInt = 256/nIntervalos;
    if(256%nIntervalos != 0){
        tamInt++;
    }
    hist->tamanhoIntervalo = tamInt;
    void * dados;
    dados = ObterDadosImagem(img);
    int altura = ObterAlturaImagem(img), largura = ObterLarguraImagem(img);
    Tipo tipo = ObterTipoImagem(img);

    int minimoIntervalo=0;
    for(int i = 0; i < nIntervalos; i++){
        minimoIntervalo = i*tamInt;

        for(int j = 0; j < largura*altura; j++){
            if(tipo == FLOAT){
                int num;
                float intermediario=((float*)dados)[j];
                num = (int)(intermediario*255);
                if(num >= minimoIntervalo && num < (minimoIntervalo + tamInt)){
                    hist->intervalos[i]++;
                }
            }

            if(tipo == INT){
                int num;
                num = (((int*)dados)[j]) ;
                //printf("(%d)", num);
                if(num >= minimoIntervalo && num < (minimoIntervalo + tamInt)){
                    hist->intervalos[i]++;
                }
            }
            
        }

        
    }

    return hist;
}

/**
 * @brief Função para exibir um histograma na tela.
 * @param histogram O histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma){
    for(int i = 0; i < histograma->numeroInt; i++){
        int minimoIntervalo = i*histograma->tamanhoIntervalo;
        printf("[%d, %d): %d\n", minimoIntervalo, minimoIntervalo+histograma->tamanhoIntervalo, histograma->intervalos[i]);
        
            //[52, 104): 28799
    }

}

/**
 * @brief Função para destruir um histograma.
 * @param histogram O histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma){
    if(histograma){
        if(histograma->intervalos){
            free(histograma->intervalos);
        }
        free(histograma);
    }
}