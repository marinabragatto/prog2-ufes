#include "cidade.h"

int main(){
    tCidade cidade;
    
    cidade = CriaCidade();
    LeEntrada(cidade);
    ProcessaAtaques(cidade);
    ImprimeDados(cidade);
    LiberaCidade(cidade);

    return 0;
}