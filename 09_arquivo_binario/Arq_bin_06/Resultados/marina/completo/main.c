#include <stdio.h>
#include "estabelecimento.h"
#include "vector.h"

int main(){
    char caminho[100];

    tEstabelecimento * Estabelecimento;
    Estabelecimento = CriaEstabelecimento();
    LeEstabelecimento(Estabelecimento);

    ImprimeRelatorioEstabelecimento(Estabelecimento);
    DestroiEstabelecimento(Estabelecimento);



    return 0;
}