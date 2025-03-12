#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"

int main(){
    char caminho[200];
    scanf("%s\n", caminho);
    int nintervalos;
    scanf("%d", &nintervalos);
    Imagem * img;
    img = LerImagem(caminho);
    Histograma * hist;
    hist = CalcularHistograma(img, nintervalos);
    MostrarHistograma(hist);
    DestruirHistograma(hist);
    DestruirImagem(img);
    return 0;
}