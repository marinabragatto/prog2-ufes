#include "agencia.h"
#include <stdlib.h>
#include <string.h>
/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia {
    Vector * contas;
    int nAgencia;
    char * nome;
    int tamanho ;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia(){
    tAgencia * agencia;
    agencia = (tAgencia*)malloc(sizeof(tAgencia));
    agencia->contas = VectorConstruct();
    agencia->nAgencia = 0;
    agencia->tamanho = 0;
    return agencia;
}


/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia){
    if(agencia){
        if(((tAgencia*)agencia)->nome){
            free(((tAgencia*)agencia)->nome);
        }
        if(((tAgencia*)agencia)->contas){
            VectorDestroy(((tAgencia*)agencia)->contas, DestroiConta);
        }
        free(agencia);
    }
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia){
    char nome[200];
    scanf("%*[^0-9-]");
    scanf("%d;", &agencia->nAgencia);
    scanf("%[^\n]", nome);
    int tam = strlen(nome);

    agencia->nome = (char*)malloc(sizeof(char)*(tam+1));
    strcpy(agencia->nome, nome);
    //111;Goiabeiras
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta){
    VectorPushBack(agencia->contas, conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2){
    if(agencia2->nAgencia == numAgencia){
        return 1;
    }
    return 0;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia){
    int i = 0;
    float soma = 0;
    tConta * atual;
    for(i = 0; i < VectorSize(agencia->contas); i++){
        
        atual = VectorGet(agencia->contas, i);
        soma += GetSaldoConta(atual);
    }
    soma = soma/VectorSize(agencia->contas);
    return soma;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia){
    printf("\tNome: %s\n\tNumero: %d\n\tNumero de contas cadastradas: %d\n\tSaldo médio: R$%.2f\n\n", agencia->nome, agencia->nAgencia, VectorSize(agencia->contas), GetSaldoMedioAgencia(agencia));
}