#include "banco.h"
#include <stdio.h>

#define CONTAS_ALOCADAS 5

int RetornaIdxConta(tConta ** contas, int numeroConta, int qtdContas);


/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco(){
    tBanco * banco;
    int i = 0, contasAlocadas;

    banco = (tBanco*)malloc(sizeof(tBanco));
    if(!banco){
        printf("nao foi possivel alocar um banco!\n");
    }

    banco->contas = (tConta**)malloc(sizeof(tConta*)*CONTAS_ALOCADAS);
    if(!banco->contas){
        printf("nao foi possivel alocar um vetor de contas!\n");
    }


    for(i = 0 ; i < CONTAS_ALOCADAS; i++){
        banco->contas[i] = NULL;
    }
    banco->contasAlocadas = CONTAS_ALOCADAS;
    banco->qtdContas = 0;
    return banco;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco){
    int i = 0;

    if(banco){
        for(i = 0; i < banco->qtdContas; i++){
            DestroiConta(banco->contas[i]);
        }
        if(banco->contas){
            free(banco->contas);
        }
        else {
            printf("tentou liberar um ponteiro tContas** jah nulo!\n");
        }
        free(banco);
    }
    else {
        printf("tentou liberar um ponteiro tBanco jah nulo!\n");
        exit(1);
    }
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco){
    banco->contas[banco->qtdContas] = CriaConta();
    if(!banco->contas[banco->qtdContas]){
        printf("nao foi possivel alocar uma conta!\n");
    }
    LeConta(banco->contas[banco->qtdContas]);
    banco->qtdContas++;
    return;
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco){
    float valor = 0 ;
    int conta = 0, idx = 0;
    scanf("%d %f\n", &conta, &valor);
    idx  = RetornaIdxConta(banco->contas, conta, banco->qtdContas);
    SaqueConta(banco->contas[idx], valor);
    return;
//1 100 
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco){
    float valor = 0 ;
    int conta = 0, idx = 0;
    scanf("%d %f\n", &conta, &valor);
    idx  = RetornaIdxConta(banco->contas, conta, banco->qtdContas);
    DepositoConta(banco->contas[idx], valor);
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco){
    int destino = 0, origem = 0;
    float valor = 0;

    scanf("%d %d %f\n", &destino, &origem, &valor);

    int destinoIdx = 0, origemIdx = 0;
    destinoIdx = RetornaIdxConta(banco->contas, destino, banco->qtdContas);
    origemIdx = RetornaIdxConta(banco->contas, origem, banco->qtdContas);

    if( destinoIdx != -1 && origemIdx!= -1){ //verifica se as contas existem
        TransferenciaConta(banco->contas[destinoIdx], banco->contas[origemIdx], valor);
    }
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco){
    int i = 0;
    printf("===| Imprimindo Relatorio |===\n");
    for(i = 0; i < banco->qtdContas; i++){
        ImprimeConta(banco->contas[i]);
    }
    
}

int RetornaIdxConta(tConta ** contas, int numeroConta, int qtdContas){
    int i = 0;
    for(i = 0; i < qtdContas;i++){
        if(VerificaConta(contas[i], numeroConta)){
            return i;
        }
    }
    return -1;
}