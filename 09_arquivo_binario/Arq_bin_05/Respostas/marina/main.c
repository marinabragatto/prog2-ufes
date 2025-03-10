#include <stdio.h>
#include "estabelecimento.h"
#include "produto.h"


int main(){
    tEstabelecimento * Estabelecimento;
    Estabelecimento = CriaEstabelecimento();
    LeEstabelecimento(Estabelecimento);
    ImprimeProdutosEmFaltaEstabelecimento(Estabelecimento);

    DestroiEstabelecimento(Estabelecimento);

    return 0;
}