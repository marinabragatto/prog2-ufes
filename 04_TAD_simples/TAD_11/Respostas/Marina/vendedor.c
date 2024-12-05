#include "vendedor.h"
#include "string.h"
#include <stdio.h>


tVendedor RegistraVendedor(char nome[50], float salario, float prct_comissao){
    tVendedor vendedor;
    
    strcpy(vendedor.nome, nome);

    vendedor.salario = salario;
    vendedor.prct_comissao = prct_comissao;
    vendedor.valor_vendido = 0;
    return vendedor;
}

int VerificaNomeVendedor(tVendedor vendedor, char nome[50]){
    return (strcmp(vendedor.nome, nome) == 0) ? 1 : 0;
}

tVendedor ContabilizaVenda(tVendedor vendedor, float valor){
    vendedor.valor_vendido += valor;
    return vendedor;
}

float GetSalario(tVendedor vendedor){
    return vendedor.salario;
}

float GetComissao(tVendedor vendedor){
    return (vendedor.prct_comissao*vendedor.valor_vendido);
}

float GetTotalVendido(tVendedor vendedor){
    return vendedor.valor_vendido;
}

float GetTotalRecebido(tVendedor vendedor){
    float comissao = 0;
    comissao = GetComissao(vendedor);
    return (vendedor.salario + comissao);
}

/**
 * @brief Imprime o relatório de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 */
void ImprimeRelatorioVendedor(tVendedor vendedor){
    printf("\t%s > Total vendido: R$%.2f\n\t\tTotal recebido: R$%.2f\n", vendedor.nome, GetTotalVendido(vendedor), GetTotalRecebido(vendedor));
    return;
}
