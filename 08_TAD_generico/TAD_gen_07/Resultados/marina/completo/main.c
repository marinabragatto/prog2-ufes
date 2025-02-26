#include "histograma.h"

int main(){
    int nIntervalos;
    scanf("%d", &nIntervalos);
    Imagem * imagem;

    imagem = LerImagem();

    Histograma * hist;
    hist = CalcularHistograma(imagem, nIntervalos);
    MostrarHistograma(hist);
    DestruirHistograma(hist);
    DestruirImagem(imagem);

    return 0;
}