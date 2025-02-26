#include "banco.h"

int main(){
    tBanco * banco;
    //printf("oi");
    banco = CriaBanco();
    LeBanco(banco);
    //impre
    char op = 'a';


    while(1){
        scanf("%*[^A-Za-z]");
        scanf("%c\n",&op);
        if(op == 'A'){
            tAgencia  * agencia;
            agencia = CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco, agencia);
        }
        else if(op == 'C'){
            tConta * conta;
            conta = CriaConta();
            LeConta(conta);
            int numAgencia = 0;
            scanf("%d\n", &numAgencia);
            InsereContaBanco(banco, numAgencia, conta);

        }
        else if(op == 'F'){
            break;
        }

    }
    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);
    return 0;
}