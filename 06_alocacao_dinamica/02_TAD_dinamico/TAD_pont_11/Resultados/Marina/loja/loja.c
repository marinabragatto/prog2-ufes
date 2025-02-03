#include "loja.h"
#include <stdlib.h>

#define NUM_MIN_VEND 5

/**
 * @brief Abre uma nova loja.
 * 
 * @param id ID da loja.
 * @param aluguel Valor do aluguel da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja com os dados da loja aberta.
 */
tLoja* AbreLoja(int id, float aluguel){
    tLoja *loja;

    
    loja = (tLoja*)malloc(sizeof(tLoja));
    loja->id = id;
    loja->aluguel = aluguel;
    loja->lucro = 0;
    loja->maxVendedores = NUM_MIN_VEND;
    loja->totalVendedores = 0;
    loja->vendedores = (tVendedor**)malloc(sizeof(tVendedor*)*NUM_MIN_VEND);
    //printf("ola");
    return loja;
}

/**
 * @brief Libera a memória alocada para uma loja.
 * 
 * @param loja Ponteiro para uma loja a ser apagado.
 */
void ApagaLoja(tLoja* loja){
    int i = 0;
    if(loja){
        if(loja->vendedores){
            for(i = 0; i < loja->totalVendedores; i++){
                if(loja->vendedores[i]){
                    ApagaVendedor(loja->vendedores[i]);
                }
            }
            free(loja->vendedores);
        }
        free(loja);
    }
}

/**
 * @brief Verifica se o ID de uma loja é igual a outro.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja a ser verificada.
 * @param id ID da loja a ser comparado.
 * @return int Retorna 1 se o ID da loja é igual ao ID passado como parâmetro, ou 0 caso contrário.
 */
int VerificaIdLoja(tLoja* loja, int id){
    return (loja->id == id);
}

/**
 * @brief Contrata um novo vendedor para a loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser contratado.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o novo vendedor contratado.
 */
void ContrataVendedor(tLoja* loja, tVendedor* vendedor){
    if(loja->totalVendedores >= loja->maxVendedores && loja->totalVendedores != 0){
        loja->maxVendedores += NUM_MIN_VEND;
        loja->vendedores = (tVendedor**)realloc(loja->vendedores, sizeof(tVendedor*)*loja->maxVendedores);
    }

    loja->vendedores[loja->totalVendedores] = vendedor;
    loja->totalVendedores++;
}

/**
 * @brief Registra uma nova venda para um vendedor da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param nome Nome do vendedor que realizou a venda.
 * @param valor Valor da venda a ser registrada.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com a venda registrada.
 */
void RegistraVenda(tLoja* loja, char* nome, float valor){
    int i = 0;

    for(i = 0; i < loja->totalVendedores; i++){
        if(VerificaNomeVendedor(loja->vendedores[i], nome)){
            ContabilizaVenda(loja->vendedores[i], valor);
            break;
        }
    }
}

/**
 * @brief Calcula o lucro da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o lucro calculado.
 */
void CalculaLucro(tLoja* loja){
    float totalRecebido = 0, totalVendido = 0;
    int i = 0;
    for(i = 0; i < loja->totalVendedores;i++){
        totalVendido += GetTotalVendido(loja->vendedores[i]);
        totalRecebido += GetTotalRecebido(loja->vendedores[i]);
    }
    loja->lucro = totalVendido - totalRecebido - loja->aluguel; 
}

/**
 * @brief Imprime o relatório da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 */
void ImprimeRelatorioLoja(tLoja* loja){
    int i  = 0;
    printf("Loja %d: Lucro total: R$ %.2f\n", loja->id, loja->lucro);
    for(i = 0; i < loja->totalVendedores; i++){
        ImprimeRelatorioVendedor(loja->vendedores[i]);
    }
    return;
}