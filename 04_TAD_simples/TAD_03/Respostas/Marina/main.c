#include <stdio.h>
#include <string.h>
#include "locadora.h"

int main(){
    tLocadora locadora;
    locadora = criarLocadora();
    scanf("%*[^a-zA-Z]");
    char opcao[15];
    int ret = 0;
    int i = 0;

    while(1){
        ret = scanf("%[^\n ]", opcao);
        if(ret == -1 || ret == 0){
            break;
        }
        if(i != 0){
            printf("\n");
        }
        if(strcmp(opcao, "Alugar") == 0){
            locadora = lerAluguelLocadora(locadora);
        }
        else if(strcmp(opcao, "Estoque") == 0){
            locadora = ordenarFilmesLocadora(locadora);
            consultarEstoqueLocadora (locadora);
        }
        else if(strcmp(opcao, "Devolver") == 0){
            locadora = lerDevolucaoLocadora(locadora);
        }
        else if(strcmp(opcao, "Cadastrar") == 0){
            locadora = lerCadastroLocadora(locadora);
        }
        scanf("%*[^a-zA-Z]");
        i++;
    }    

    consultarLucroLocadora(locadora);
    return 0;
}

/*Alugar
1
#
Estoque
#
Devolver
1
#
Estoque
#*/