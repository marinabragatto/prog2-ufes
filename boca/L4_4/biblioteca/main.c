#include <stdio.h>
#include "cabeçalho.h"
#include <math.h>

int main(){
    int qtd = 0, i = 0;

    scanf("%d", &qtd);
    
    tPonto pontos[qtd];

    for (i = 0; i < qtd; i++){
        pontos[i] = inicializaPontoEntrada(pontos[i]);
        imprimePonto(pontos[i]);
        printf(" %d ", retornaQuadrante(pontos[i]));
        tPonto simetrico;
        simetrico = retornaSimetrico(pontos[i]);
        imprimePonto(simetrico);
        printf(" %d\n", retornaQuadrante(simetrico));

    }
    return 0;
}