#include "loja.h"
#include <stdio.h>


tLoja AbreLoja(int id, float aluguel){
    tLoja loja;
    loja.id = id;
    loja.aluguel = aluguel;
    loja.totalVendedores = 0;
    loja.lucro = 0;
    return loja;
}

int VerificaIdLoja(tLoja loja, int id){
    return (loja.id == id) ? 1 : 0;
}


tLoja ContrataVendedor(tLoja loja, tVendedor vendedor){
    loja.vendedores[loja.totalVendedores] = vendedor;
    loja.totalVendedores++;
    return loja;
}


tLoja RegistraVenda(tLoja loja, char nome[50], float valor){
    int i = 0;

    for(i = 0; i < loja.totalVendedores; i++){
        if(VerificaNomeVendedor(loja.vendedores[i], nome)){
            loja.vendedores[i] = ContabilizaVenda(loja.vendedores[i], valor);
            break;
        }
    }
    return loja;
}

tLoja CalculaLucro(tLoja loja){
    int i = 0;

    for(i = 0; i < loja.totalVendedores; i++){
        loja.lucro += GetTotalVendido(loja.vendedores[i]) - GetTotalRecebido(loja.vendedores[i]);
    }
    loja.lucro = loja.lucro - loja.aluguel;

    return loja;
}


void ImprimeRelatorioLoja(tLoja loja){
    int i = 0; 


    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);

    for(i = 0; i < loja.totalVendedores; i++){
        ImprimeRelatorioVendedor(loja.vendedores[i]);
    }
	return;
}