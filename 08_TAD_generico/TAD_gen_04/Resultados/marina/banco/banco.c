#include "banco.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura para representar um banco.
 */
struct Banco {
    Vector * agencias;
    char * nome;
};

/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco(){
    tBanco * banco;
    banco = (tBanco*)malloc(sizeof(tBanco));
    banco->nome = NULL;
    banco->agencias = VectorConstruct();
    return banco;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco){
    if(banco){
        if(banco->agencias){
            VectorDestroy(banco->agencias, DestroiAgencia);
        }
        if(banco->nome){
            free(banco->nome);
        }
        free(banco);
    }

}

/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco){
    char nome[200];
    scanf("%*[^a-zA-Z]");
    scanf("%[^\n]\n", nome);

    int tam = strlen(nome);

    banco->nome = (char*)malloc(sizeof(char)*(tam+1));
    strcpy(banco->nome, nome);

}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia){
    VectorPushBack(banco->agencias, agencia);
}

/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
*/
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente){
    int i = 0;
    for(i = 0; i < VectorSize(banco->agencias); i++){
        if(ComparaAgencia(numAgencia,VectorGet(banco->agencias, i))){
            AdicionaConta(VectorGet(banco->agencias, i), cliente);
        }
    }
}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco){
    printf("%s\nLista de agencias:\n", banco->nome);
    int i = 0; 
    for(i = 0; i < VectorSize(banco->agencias); i++){
        ImprimeDadosAgencia(VectorGet(banco->agencias, i));
    }
}