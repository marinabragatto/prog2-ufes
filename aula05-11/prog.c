#include <stdio.h>
#include "tData.h"

int main(){
    int qtd = 0, i = 0;
    scanf("%d", &qtd);
    tData datas[qtd];
    for(i = 0; i < qtd; i++){
        datas[i] = leData();
        imprimeData(datas[i]);
    }    
    return 0;
}



/*o “’dd/mm/aaaa’”

x. se o 
mês fornecido for maior do que 12, a data criada deverá ser com mês 12. O mesmo 
critério deverá ser usado para o dia considerando o mês em questão.  */