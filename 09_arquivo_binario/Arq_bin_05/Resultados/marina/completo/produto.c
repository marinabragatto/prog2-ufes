#include "produto.h"
#include <string.h>
#include <stdlib.h>

#define TAM_MAX_NOME 50

/**
 * @brief Estrutura para representar um produto.
 */
struct Produto {
    int codigo;
    char nome[TAM_MAX_NOME];
    float preco;
    int quantidade;
};

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidade){
    tProduto * Produto;
    Produto = (tProduto*)malloc(sizeof(tProduto));
    Produto->codigo = codigo;
    Produto->preco = preco;
    Produto->quantidade = quantidade;
    strcpy(Produto->nome, nome);

    return Produto;
}

/**
 * @brief Função para destruir um produto.
 * @param produto Um ponteiro para o produto a ser destruído.
 */
void DestroiProduto(tProduto *produto){
    if(produto){
        free(produto);
    }
}

/**
 * @brief Função para ler um produto de um arquivo binário.
 * @param arquivo O arquivo de onde o produto será lido.
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
    int quantidade;
    fread(&codigo, sizeof(int), 1, arquivo);
    fread(nome, sizeof(char), TAM_MAX_NOME, arquivo);
    fread(&preco, sizeof(float), 1, arquivo);
    fread(&quantidade, sizeof(int), 1, arquivo);
    tProduto * Produto;
    Produto = CriaProduto(codigo, nome, preco, quantidade);

    return Produto;
}

/**
 * @brief Função para verificar se um produto tem estoque.
 * @param produto Um ponteiro para o produto.
 * @return 1 se o produto tem estoque, 0 caso contrário.
 */
int TemEstoqueProduto(tProduto *produto){
    if(produto->quantidade>0){
        return 1;
    }
    return 0;
}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto){
    printf("%d;%s;%.2f\n", produto->codigo, produto->nome, produto->preco);
}