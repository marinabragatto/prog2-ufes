#include "estabelecimento.h"
#include "vector.h"
/**
 * @brief Estrutura para representar um estabelecimento.
 */
struct Estabelecimento {
    Vector * Produto;
    int qtdProdutos;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento(){
    tEstabelecimento * Estabelecimento;
    Estabelecimento = (tEstabelecimento*)malloc(sizeof(tEstabelecimento));
    Estabelecimento->qtdProdutos = 0;
    Estabelecimento->Produto = VectorConstruct();
    return Estabelecimento;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento){
    if(estabelecimento){

        if(estabelecimento->Produto){
            VectorDestroy(estabelecimento->Produto, DestroiProduto);
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
    VectorPushBack(estabelecimento->Produto, produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento){
    int i = 0;
    char nomeArq[100];

    scanf("%s", nomeArq);

    FILE * arquivo;
    arquivo = fopen(nomeArq, "rb");
    int tamanho = 0, qtd = 0;

    fread(&qtd, sizeof(int), 1, arquivo);
    estabelecimento->qtdProdutos = qtd;

    for(i = 0; i < qtd; i++){
        tProduto * Produto;
        Produto = LeProduto(arquivo);
        VectorPushBack(estabelecimento->Produto, Produto);
    }
    fclose(arquivo);
}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento){
    printf("Produtos em falta:\nCodigo;Nome;Preco\n");
    int possui = 0;

    for(int i = 0; i < VectorSize(estabelecimento->Produto); i++){
        if(!TemEstoqueProduto(VectorGet(estabelecimento->Produto, i))){
            ImprimeProduto(VectorGet(estabelecimento->Produto, i));
            possui = 1;
        }
        
    }
    if(possui == 0){
        printf("Nao ha produtos em falta!\n");
    }
    
}