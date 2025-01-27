#include <stdio.h>
#include "locadora.h"
#include <string.h>

int main(){
    char operacao[20];
    int ret = 0;
    tLocadora *locadora;
    locadora = CriarLocadora();
    int i = 1;
    //scanf("%19s\n", operacao);
  //  printf("(%s)", operacao);
    
    //printf("\n");
    while(1){
       
        if(i != 1){
            printf("\n");
            scanf("%*c");
        
        }
        
        ret = scanf("%19s\n", operacao);
       // printf("(%s)", operacao);
        if(ret != 1){
            break;
        }
        if(strcmp(operacao, "Alugar") == 0){
            LerAluguelLocadora(locadora);

        }else if(strcmp(operacao, "Devolver") == 0){
            LerDevolucaoLocadora(locadora);
        } else if(strcmp(operacao, "Estoque") == 0){
            OrdenarFilmesLocadora(locadora);
            ConsultarEstoqueLocadora(locadora);
        }
        else if(strcmp(operacao, "Cadastrar") == 0){
            LerCadastroLocadora(locadora);
        }
        i++;
    }
    
    ConsultarLucroLocadora(locadora);  
    DestruirLocadora(locadora);
    return 0;
}