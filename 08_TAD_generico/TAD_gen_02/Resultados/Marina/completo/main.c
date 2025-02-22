#include <stdio.h>
#include "gerenciadorpacotes.h"

void imprimeMenu();

int main(){
    printf("tad_gen_02\n");
    int op;
    tGerenciador  * gerencia;
    gerencia = CriaGerenciador();

    while(1){
        printf("\n");
        imprimeMenu();
        scanf("%*[^0-9]");
        scanf("%d", &op);
        if(op == 1){
            int chOrInt = -1, tam = -1;
            printf("\nDigite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: ");
            scanf("%d %d\n", &chOrInt, &tam);
            tPacote * pacote;
            if(chOrInt == 0){
                pacote = CriaPacote(CHAR, tam);
                LePacote(pacote);
                AdicionaPacoteNoGerenciador(gerencia, pacote);
            }
            else if(chOrInt == 1){
                pacote = CriaPacote(INT, tam);
                LePacote(pacote);
                AdicionaPacoteNoGerenciador(gerencia, pacote);
            }
            else{
                printf("\nDigite um tipo valido!");
            }
            
    
        }
        else if(op == 2){
            int idx = -1;
            
            scanf("%d\n", &idx);
            ImprimirPacoteNoIndice(gerencia, idx);
        }
        else if(op == 3){
            printf("\n");
            ImprimirTodosPacotes(gerencia);

            break;
        }
        else {
            printf("\nEscolha uma opcao valida para o menu!");
        }
    }
     

    DestroiGerenciador(gerencia);
    return 0;
}

void imprimeMenu(){
    printf("Escolha uma opcao:\n\t(1) Cadastrar um novo pacote\n\t(2) Imprimir um pacote específico\n\t(3) Imprimir todos os pacotes e sair");
}