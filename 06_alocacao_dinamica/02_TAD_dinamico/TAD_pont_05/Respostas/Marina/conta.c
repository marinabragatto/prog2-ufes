#include "conta.h"

//typedef struct Conta {
 //   int numero;
  //  float saldo;
  //  tUsuario *user;
//} tConta;

/**
 * @brief Cria uma nova conta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para a nova conta criada.
 */
tConta *CriaConta(){
    tConta *conta;
    conta = (tConta*)malloc(sizeof(tConta));
    if(!conta){
        printf("nao alocou a conta!\n");
        exit(1);
    }
    conta->user = CriaUsuario();
    conta->numero = -1;
    conta->saldo = 0;
    return conta;
}
/**
 * @brief Desaloca a memória de uma conta.
 * 
 * @param conta Ponteiro para a conta a ser destruída.
 */
void DestroiConta(tConta *conta){

    if(conta){
        if(conta->user){
            DestroiUsuario(conta->user);
        }
        else {
            printf("tentou liberar um tUser nulo!\n");
            exit(1);
        }
        free(conta);
    }else{
        printf("tentou liberar um ponteiro tConta jah nulo!\n");
        exit(1);
    }
    return;
}

/**
 * @brief Lê os dados de uma conta e do usuario atraves da entrada padrão.
 * 
 * @param conta Ponteiro para a conta a ser lida.
 */
void LeConta(tConta *conta){
    scanf("%*[^a-zA-Z]");
    LeUsuario(conta->user);
    scanf("%*[^0-9]");
    scanf("%d\n", &conta->numero);
    
    return;
}

/**
 * @brief Imprime os dados de uma conta e do proprietário.
 * 
 * @param conta Ponteiro para a conta a ser impressa.
 */
void ImprimeConta(tConta *conta){
    printf("Conta: %d\nSaldo: R$ %.2f\n", conta->numero, conta->saldo);
    ImprimeUsuario(conta->user);
    return;
}

/**
 * @brief Verifica se uma conta possui o numero especificado.
 * 
 * @param conta Ponteiro para a conta a ser verificada.
 * @param numero Número da conta a ser verificado.
 * @return 1 se a conta possui o número especificado, 0 caso contrário.
 */
int VerificaConta(tConta *conta, int numero){
    if(conta->numero == numero){
        return 1;
    }
    else{
        return 0;
    }
}

/**
 * @brief Realiza um saque em uma conta caso o saldo seja suficiente.
 * 
 * @param conta Ponteiro para a conta a ser sacada.
 * @param valor Valor a ser sacado.
 */
void SaqueConta(tConta *conta, float valor){
    if(conta->saldo >= valor){
        conta->saldo -= valor;
    }

}
/**
 * @brief Realiza um depósito em uma conta.
 * 
 * @param conta Ponteiro para a conta a ser depositada.
 * @param valor Valor a ser depositado.
 */
void DepositoConta(tConta *conta, float valor){
    conta->saldo += valor;
}

/**
 * @brief Realiza uma transferência entre duas contas, caso o saldo da conta de origem seja suficiente.
 * 
 * @param destino Ponteiro para a conta de destino.
 * @param origem Ponteiro para a conta de origem.
 * @param valor Valor a ser transferido.
*/
void TransferenciaConta(tConta *destino, tConta *origem, float valor){
    if(origem->saldo >= valor){
        origem->saldo -= valor;
        destino->saldo += valor;
    }
}

