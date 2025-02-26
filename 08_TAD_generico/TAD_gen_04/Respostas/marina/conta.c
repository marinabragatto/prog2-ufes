#include "conta.h"
#include <string.h>
#include <stdlib.h>
/**
 * @brief Estrutura para representar uma conta bancária.
 */
struct Conta {
    float saldo;
    char * nome;
    int nConta;
};

/**
 * @brief Função para criar uma nova conta bancária.
 * @return Um ponteiro para a nova conta bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tConta *CriaConta(){
    tConta * conta;
    conta = (tConta*)malloc(sizeof(tConta));
    conta->nConta = 0;
    conta->nome = '\0';
    conta->saldo = 0;
    return conta;
}

/**
 * @brief Função para destruir uma conta bancária.
 * @param conta A conta bancária a ser destruída.
 */
void DestroiConta(DataType conta){
    if(conta){
        if(((tConta*)conta)->nome){
            free(((tConta*)conta)->nome);
        }
        free(conta);
    }
}

/**
 * @brief Função para ler uma conta bancária no formato "numero;nome do cliente;saldo inicial".
 * @param conta A conta bancária a ser lida.
 */
void LeConta(tConta *conta){
    char nome[200];

    scanf("%*[^0-9-]");
    int nConta = 0;
    float saldo = 0;
    scanf("%d;", &nConta);
    scanf("%[^;]", nome);
    scanf("%*[;]");
    scanf("%f\n", &saldo);
   conta->nConta =nConta;
   conta->saldo = saldo;
    int tam = strlen(nome);
    conta->nome = (char*)malloc(sizeof(char)*(tam+1));
    strcpy(conta->nome, nome);

    //1;Goku;1500.21
}

/**
 * @brief Função para obter o saldo de uma conta bancária.
 * @param conta A conta bancária.
 * @return O saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta){
    return conta->saldo;
}