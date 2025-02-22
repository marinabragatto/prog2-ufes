#include <stdio.h>
#include "banco.h"

int main(){
    char operacao = 'a';
    tBanco *banco;
    banco = CriaBanco();

    while(1){
        scanf("%c\n", &operacao);
        if(operacao == 'F'){
            break;
        }
        else if(operacao == 'R'){
            ImprimeRelatorioBanco(banco);
        }
        else if(operacao == 'S'){
            SaqueContaBanco(banco);
        }
        else if(operacao == 'D'){
            DepositoContaBanco(banco);
        }
        else if(operacao == 'T'){
            TransferenciaContaBanco(banco);
        }
        else if(operacao == 'A'){
            AbreContaBanco(banco);
        }
        else{
            printf("Opcao invalida!\n");
        }

    }
    DestroiBanco(banco);
    return 0;
}