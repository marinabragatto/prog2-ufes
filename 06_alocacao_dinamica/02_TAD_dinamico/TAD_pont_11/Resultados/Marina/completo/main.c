#include <stdio.h>
#include "loja.h"

// (0 - Sair; 1 – Abrir loja; 2 – Contratar vendedor; 3 – Registrar
// venda; 4 – Relatorio geral).

int RetornaIdxLoja(tLoja *lojas[], int qtdEfetiva, int id);

int main(){
    int qtd = 0;
    scanf("%d\n", &qtd);
    //int i = 0;
    tLoja *lojas[qtd];
    
    int operacao = 0, qtdEfetiva = 0;

    while(1){
        scanf("%d\n", &operacao);
        if(operacao == 0){
            break;
        }
        else if(operacao == 1){
            int id = 0;
            float aluguel = 0;
            scanf("%d %f\n", &id, &aluguel);
            lojas[qtdEfetiva] = AbreLoja(id, aluguel);
            qtdEfetiva++; 
        }
        else if(operacao == 2){
            char nome[100];
            int id = 0, idxLoja = -1;
            float salario, prct = 0;
            scanf("%99s %f %f\n", nome, &salario,&prct);
            scanf("%d\n", &id);

            tVendedor *vendedor;
            vendedor  = RegistraVendedor(nome,salario, prct);
            
            idxLoja = RetornaIdxLoja(lojas, qtdEfetiva, id);
            ContrataVendedor(lojas[idxLoja], vendedor);
        }
        else if(operacao == 3){
            char nome[100];
            int id = 0, idxLoja = -1;
            float valor = 0;
            scanf("%d %99s %f\n", &id, nome, &valor);
            //printf("%s", nome);
            idxLoja = RetornaIdxLoja(lojas, qtdEfetiva, id);
            RegistraVenda(lojas[idxLoja], nome, valor);
        }
        else if(operacao == 4){
            int i = 0;
            for (i = 0; i < qtdEfetiva;i++){
                CalculaLucro(lojas[i]);
                ImprimeRelatorioLoja(lojas[i]);
            }
        }
    }

    int j = 0;
    for(j = 0; j < qtdEfetiva;j++){
        ApagaLoja(lojas[j]);
    }

    return 0;
}

int RetornaIdxLoja(tLoja *lojas[], int qtdEfetiva, int id){
    int i = 0;
    for(i = 0; i < qtdEfetiva;i++){
        if(VerificaIdLoja(lojas[i], id)){
            return i;
        }
    }
    return -1;
}