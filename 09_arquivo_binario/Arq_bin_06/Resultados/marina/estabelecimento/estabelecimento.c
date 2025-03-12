#include <stdlib.h>
#include "estabelecimento.h"
#include "vector.h"

/**
 * @brief Estrutura para representar um estabelecimento.
 */
struct Estabelecimento {
    Vector * produtos;

}
;

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento(){
    tEstabelecimento * Estabelecimento;
    Estabelecimento = (tEstabelecimento*)malloc(sizeof(tEstabelecimento));

    Estabelecimento->produtos = VectorConstruct();

    return Estabelecimento;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento){
    if(estabelecimento){
        if(estabelecimento->produtos){
            VectorDestroy(estabelecimento->produtos, DestroiProduto);
        }

        free(estabelecimento);
    }
}
/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto){
    VectorPushBack(estabelecimento->produtos, produto);
}
/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento){
    char nomeArq[50];
    scanf("%s\n", nomeArq);
    FILE* arq;
    arq = fopen(nomeArq, "rb");
    int qtd;

    fread(&qtd, sizeof(int), 1, arq);

    int i = 0;
    for(i = 0; i < qtd; i++){
        tProduto * Produto = LeProduto(arq);
        VectorPushBack(estabelecimento->produtos, Produto);
    }
    fclose(arq);

}

/**
 * @brief Função para obter o valor total de produtos vendidos em um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @return O valor total de produtos vendidos.
*/
float GetValorTotalVendidoEstabelecimento(tEstabelecimento *estabelecimento){
    int qtdProd = VectorSize(estabelecimento->produtos);
    float soma = 0;
    for(int i = 0; i < qtdProd; i++){
        tProduto * Produto;
        Produto = VectorGet(estabelecimento->produtos, i);
        soma+=GetPrecoProduto(Produto)*GetQuantidadeVendidaProduto(Produto);
    }
    return soma;
}
/**
 * @brief Função para imprimir na tela um relatório de um estabelecimento, cotendo o valor total vendido e a porcentagem de cada produto relativo ao total vendido.
 * Formato: Codigo;Nome;Preco;Quantidade vendida
 * @param estabelecimento Um ponteiro para o estabelecimento.
*/
void ImprimeRelatorioEstabelecimento(tEstabelecimento *estabelecimento){
    /*
    Valor total vendido: R$ 9336.50
Produtos vendidos:
Codigo;Nome;Preco;Quantidade vendida;Porcentagem
100;caneta;R$ 4.50;150;7.23%
101;lapis;R$ 2.50;984;26.35%
102;caderno;R$ 12.00;150;19.28%
103;agenda;R$ 8.50;59;5.37%
104;pincel;R$ 10.00;390;41.77%

    */
   int qtd = 0;
   float perce;
   qtd=VectorSize(estabelecimento->produtos);
    float soma = 0;
   printf("Valor total vendido: R$ %.2f\n", GetValorTotalVendidoEstabelecimento(estabelecimento));
   printf("Produtos vendidos:\n");
   printf("Codigo;Nome;Preco;Quantidade vendida;Porcentagem\n");
    for(int i = 0; i <  qtd; i++){
        
        tProduto * prod = VectorGet(estabelecimento->produtos, i);
        ImprimeProduto(prod);
        soma =GetPrecoProduto(prod)*GetQuantidadeVendidaProduto(prod);
        perce = (soma/GetValorTotalVendidoEstabelecimento(estabelecimento))*100;
        printf(";%.2f%%\n", perce);
    }

}