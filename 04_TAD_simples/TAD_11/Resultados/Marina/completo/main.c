#include "vendedor.h"
#include "loja.h"
#include <stdio.h>

int buscaIdxDLoja(tLoja lojas[], int id, int qtdLojas);
void imprimeTodasLojas(tLoja lojas[], int qtdLojas);

int main(){
    int qtdMaxLojas = 0, operacao = 0, qtdLojas = 0, id = 0;
    float aluguel = 0;
    scanf("%d", &qtdMaxLojas);
    //printf("oi");
    tLoja lojas[qtdMaxLojas];

    while(1){
        scanf("%d", &operacao);
        if(operacao == 0){
            //sair
            break;
        }
        else if(operacao == 1){
            //abrir loja
            scanf("%d %f", &id, &aluguel);
            lojas[qtdLojas] = AbreLoja(id, aluguel);
            qtdLojas++;
        }
        else if(operacao == 2){
            //contratar vendedor
            //Arthur 1500 .20
            char nome[50];
            float salario;
            float porcentagem;
            scanf("%*[^a-zA-Z]", nome);
            scanf("%[^ ]", nome);
            //printf("(%s)", nome);
            scanf("%f", &salario);
            scanf("%f", &porcentagem);

            int idxLoja = 0, idLoja = 0;
            scanf("%d", &idLoja);
            idxLoja = buscaIdxDLoja(lojas, idLoja, qtdLojas);
            tVendedor vendedor;
            vendedor =  RegistraVendedor(nome, salario, porcentagem);
            lojas[idxLoja] = ContrataVendedor(lojas[idxLoja], vendedor);
        }
        else if(operacao == 3){
            int idLoja = 0, idxLoja = 0;
            char nome[50];
            float valor = 0;
            scanf("%d %s %f", &idLoja, nome, &valor);
            idxLoja = buscaIdxDLoja(lojas, idLoja, qtdLojas);
            lojas[idxLoja] = RegistraVenda(lojas[idxLoja], nome, valor);
        }
        else if(operacao == 4){
            
            imprimeTodasLojas(lojas, qtdLojas);
        }
    }

    return 0;
}

int buscaIdxDLoja(tLoja lojas[], int id, int qtdLojas){
    int i = 0;
    for (i = 0; i < qtdLojas; i++){
        if(VerificaIdLoja(lojas[i], id)){
            return i;
        }
    }
}

void imprimeTodasLojas(tLoja lojas[], int qtdLojas){
    int i = 0; 
    for(i = 0; i < qtdLojas; i++){
        lojas[i] = CalculaLucro(lojas[i]);
        ImprimeRelatorioLoja(lojas[i]);
    }
    return;
}