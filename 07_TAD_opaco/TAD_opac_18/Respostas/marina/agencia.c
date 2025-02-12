#include "agencia.h"
#include "operacao.h"
#include <stdlib.h>

struct Agencia {
    tConta ** contas;
    int qtdContas;
    tOperacao ** operacoes;
    int qtdOp;
};

int IdxcontaCadastrada(tConta ** contas, int qtd, int idConta){
    int  i = 0; 
    for(i = 0; i < qtd; i++){
        if(ConfereIdConta(contas[i], idConta)){
            return i;
        }
    }
    return -1;
}

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tAgencia. Ponteiros devem ser inicializados com NULL e variáveis numéricas com valor zero.
 *
 * @return A variável do tipo Agencia inicializada.
 */
tAgencia* CriaAgencia(){

    tAgencia * agencia;
    agencia = (tAgencia*)malloc(sizeof(tAgencia));
    agencia->qtdContas = 0;
    agencia->qtdOp = 0;
    agencia->contas = NULL;
    agencia->operacoes = NULL;
    

    
    return agencia;
}

/**
 * @brief Libera toda a memória alocada para armazenar dados de uma agencia.
 *
 * @param A variável do tipo Agencia que será apagada.
 */
void DestroiAgencia(tAgencia* agencia){
    if(agencia){
        int i  = 0;
        if(agencia->contas){
            for(i = 0; i < agencia->qtdContas; i++){
                if(agencia->contas[i]){
                    free(agencia->contas[i]);
                }
            }
            free(agencia->contas);
        }
        
        if(agencia->operacoes){
            for(i = 0; i < agencia->qtdOp; i++){
                if(agencia->operacoes[i]){
                    free(agencia->operacoes[i]);
                }
            }
            free(agencia->operacoes);
        }
            
        free(agencia);
    }
}

/**
 * @brief Le as informações de uma agencia - contas e operações, no formato especificado no roteiro
 *
 * @param agencia - A variável do tipo agencia que salvará os dados lidos
 */
void LeOperacoes(tAgencia *agencia){
    int qtdContas = 0;
    int i = 0;

    scanf("%d\n", &qtdContas);

    agencia->contas = (tConta**)malloc(sizeof(tConta*)*qtdContas);


    int idConta = 0;

    for(i = 0; i < qtdContas;){
        scanf("%*[^0-9-]");
        scanf("%d\n", &idConta);

        if(idConta>0){
            if(IdxcontaCadastrada(agencia->contas, i, idConta) == -1){
                agencia->contas[i] = CriaConta(idConta);
                i++;
                agencia->qtdContas++;
            }
            else {
                printf("\nEste id ja esta cadastrado na agencia. Digite um id diferente!");
            }

        }
        else {
            printf("\nDigite um id valido para a conta a ser cadastrada!");
        }
    }

    int qtdOp = 0;
    scanf("%*[^0-9-]");
    scanf("%d\n", &qtdOp);


    agencia->operacoes = (tOperacao**)malloc(sizeof(tOperacao*)*qtdOp);

    float valor;
    for(i = 0; i < qtdOp;){

        scanf("%d %f\n", &idConta, &valor);
        int idxConta = -1;
        idxConta = IdxcontaCadastrada(agencia->contas, agencia->qtdContas, idConta);

        if(idxConta != -1 && idConta>0){
            agencia->operacoes[i] = CriaOperacao(agencia->contas[idxConta], valor);
            i++;
            AlteraSaldoConta(agencia->contas[idxConta], valor);
            agencia->qtdOp++;
        }
        else{
            printf("\nConta Invalida! Repita a operacao, mas com uma conta valida!");
        }
        
    }


}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param agencia - A agencia na qual queremos buscar a conta com o id específico
 * @param id - o ID da conta que queremos buscar
 *conferido
 * @return A conta, caso exista, e NULL, caso contrário
 */
tConta* BuscaContaPorId(tAgencia *agencia, int id){
    int  i = 0; 
    for(i = 0; i < agencia->qtdContas; i++){
        if(ConfereIdConta(agencia->contas[i], id)){
            break;
        }
    }
    return agencia->contas[i];
}

/**
 * @brief Função que imprime em tela as operações suspeitas de uma agência
 *
 * @param agencia A Agência na qual as operações suspeitas serão impressas em tela.
 */
void ImprimeOperacoesSuspeitas(tAgencia* agencia){
    int i = 0;
    printf("\nA lista de operações suspeitas:");
    for(i = 0 ; i < agencia->qtdOp;i++){
        if(ConsultaValorOperacao(agencia->operacoes[i]) > 20000 || ConsultaValorOperacao(agencia->operacoes[i]) < -20000){
            ImprimeOperacao(agencia->operacoes[i]);
        }
            
    }
}

/**
 * @brief Função que imprime em tela os dois correntistas com maior saldo
 *
 * @param agencia A Agência na qual os dois correntistas com maior saldo impressos em tela.
 */
void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia* agencia){
    int i = 0;

    float maiorSaldo = 0;
    int idxMaior;


    maiorSaldo = RetornaSaldoConta(agencia->contas[0]);
    idxMaior = 0;

    for(i = 0; i < agencia->qtdContas; i++){
        if(maiorSaldo < RetornaSaldoConta(agencia->contas[i])){
            maiorSaldo = RetornaSaldoConta(agencia->contas[i]);
            idxMaior = i;
        }
    }

    printf("\nOs dois correntistas com maior saldo são:\n");
    printf("Id: %d, Saldo: %.2f\n", RetornaIdConta(agencia->contas[idxMaior]), RetornaSaldoConta(agencia->contas[idxMaior]));


    int j = 0, idxSegundoMaior;

    while(1){   
        if(j != idxMaior){
            maiorSaldo = RetornaSaldoConta(agencia->contas[j]);
            idxSegundoMaior = j;
            break;
        }
        if(j >= agencia->qtdOp){
            break;
        }
        j++;
        
    }
  

    for(i = 0; i < agencia->qtdContas; i++){
        if(maiorSaldo < RetornaSaldoConta(agencia->contas[i]) && i != idxMaior){
            maiorSaldo = RetornaSaldoConta(agencia->contas[i]);
            idxSegundoMaior = i;
        }
    }

    printf("Id: %d, Saldo: %.2f\n", RetornaIdConta(agencia->contas[idxSegundoMaior]), RetornaSaldoConta(agencia->contas[idxSegundoMaior]));



}

/**
 * @brief Função que imprime em tela o saldo total da agência
 *
 * @param agencia A Agência na qual o saldo total impresso em tela.
 */
void ImprimeSaldoTotal(tAgencia* agencia){
    int i  = 0;
    float somatorio = 0;
    float saldo;
    for(i = 0 ; i < agencia->qtdContas; i++){
        saldo = RetornaSaldoConta(agencia->contas[i]);
        somatorio +=  saldo;
        
    }
    printf("O saldo total da agencia eh: %.2f\n", somatorio);
}