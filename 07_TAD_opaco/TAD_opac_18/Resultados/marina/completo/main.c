#include "agencia.h"

int main(){
    tAgencia * agencia;
    printf("--- Agencia Bancaria ---");
    agencia = CriaAgencia();
    LeOperacoes(agencia);
    ImprimeOperacoesSuspeitas(agencia);
    ImprimeDoisCorrentistasComMaiorSaldo(agencia);
    ImprimeSaldoTotal(agencia);
    DestroiAgencia(agencia);
    return 0;
}