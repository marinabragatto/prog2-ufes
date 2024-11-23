#include <stdio.h>
#include "eleicao.h"
#include "eleitor.h"
#include "candidato.h"


int main(){
    tEleicao eleicao;
    eleicao = InicializaEleicao();
    eleicao = RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);

    return 0;
}