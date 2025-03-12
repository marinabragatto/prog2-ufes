

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "produto.h"

#define TAM_MAX_NOME 50
/**
 * @brief Estrutura para representar um produto.
 */
struct Produto {
    int codigo; 
    char nome[TAM_MAX_NOME];
    float preco;
    int quantidadeVendida;
};

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidadeVendida){
    tProduto * prod;
    prod = (tProduto*)malloc(sizeof(tProduto));

    prod->codigo = codigo;
    prod->preco = preco;

    prod->quantidadeVendida = quantidadeVendida;
    strcpy(prod->nome, nome);
    return prod;
}

void DestroiProduto(tProduto *produto){
    if(produto){
        free(produto);
    }
}

/**
 * @brief Função para destruir um produto.
 *09_arquivo_binario/Arq_bin_05/correcao.sh@param arquivo O arquivo de onde o produto será lido.
 * Formato do arquivo: 
 * Código (int) 
 * Nome (string) 
 * Preço (float) 
 * Quantidade (int).
 * @return Um ponteiro para o produto lido.
 */
tProduto *LeProduto(FILE *arquivo){
    int codigo; 
    char nome[TAM_MAX_NOME];
    float preco;
    int quantidadeVendida;
    fread(&codigo, sizeof(int), 1, arquivo);
    fread(nome, sizeof(char), TAM_MAX_NOME, arquivo);
    nome[strlen(nome)] = '\0';
    fread(&preco, sizeof(float), 1, arquivo);
    fread(&quantidadeVendida, sizeof(int), 1, arquivo);
    
    tProduto * produto ;
    produto = CriaProduto(codigo, nome, preco, quantidadeVendida);

    return produto;


}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco;Quantidade vendida".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto){
    //100;caneta;R$ 4.50;150;7.23%
    
    printf("%d;%s;R$ %.2f;%d", produto->codigo, produto->nome, produto->preco, produto->quantidadeVendida, 8.9);
}

/**
 * @brief Função para obter a quantidade vendida de um produto.
 * @param produto Um ponteiro para o produto.
 * @return A quantidade vendida do produto.
 */
int GetQuantidadeVendidaProduto(tProduto *produto){
    return produto->quantidadeVendida;
}

/**
 * @brief Função para obter o preço de um produto.
 * @param produto Um ponteiro para o produto.
 * @return O preço do produto.
*/
float GetPrecoProduto(tProduto *produto){
    return produto->preco;
}