#include <stdio.h>
#include "conta.h"
#include <string.h>

void imprimeTodasContas(tConta contas[], int qtd);
int buscaContaNoSistema(tConta contas[], int conta, int qtd);

int main(){
    int qtd = 0, operacao = 0, i = 0, conta = 0, idxConta = 0;
    
    scanf("%d", &qtd);
    
    tConta contas[qtd];
    float valor = 0;

    while(1){
        scanf("%d", &operacao);
        if(operacao == 3 && i != qtd){
            char nome[20], cpf[15];
            scanf("%*[^a-zA-Z]");
            scanf("%[^ ]", nome);
            scanf("%*[^0-9]");
            scanf("%[^ ]", cpf);
            scanf("%d", &contas[i].numero);
            contas[i].user = CriaUsuario(nome, cpf);
            i++;    
        }
        else if(operacao == 1){
            scanf("%d", &conta);
            idxConta = buscaContaNoSistema(contas, conta, qtd);
            scanf("%f", &valor);
            contas[idxConta] = SaqueConta(contas[idxConta], valor);

        }
        else if(operacao == 2){
            scanf("%d", &conta);
            idxConta = buscaContaNoSistema(contas, conta, qtd);
            scanf("%f", &valor);
            contas[idxConta] = DepositoConta(contas[idxConta], valor);
            (contas[idxConta], valor);
        }
        else if(operacao == 4){
            printf("===| Imprimindo Relatorio |===\n");
            imprimeTodasContas(contas, qtd);

        }
        else if(operacao == 0){
            break;
        }
    }

    return 0;
}

int buscaContaNoSistema(tConta contas[], int conta, int qtd){
    int i = 0;
    for(i = 0; i < qtd;i++){
        if(VerificaConta(contas[i], conta)){
            return i;
        }
    } 
}

void imprimeTodasContas(tConta contas[], int qtd){
    int i = 0;
    for(i = 0; i < qtd;i++){
        ImprimeConta(contas[i]);
        printf("\n");
    } 
}