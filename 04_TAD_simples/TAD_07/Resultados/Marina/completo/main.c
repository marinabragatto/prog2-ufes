#include "data.h"
#include <stdio.h>

int main(){
    int dia1 = 0, dia2 = 0, mes1 = 0, mes2 = 0, ano1 = 0, ano2 = 0;
    tData data1, data2;

    scanf("%d/%d/%d\n", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d\n", &dia2, &mes2, &ano2);

    data1 = CriaData(dia1, mes1, ano1);
    data2 = CriaData(dia2, mes2, ano2);

    if(VerificaDataValida(data1) && VerificaDataValida(data2)){
        printf("Primeira data: ");
        ImprimeDataExtenso(data1);
        printf("Segunda data: ");
        ImprimeDataExtenso(data2);
        if(ComparaData(data1, data2) == 1){
            printf("A segunda data eh mais antiga\n");
        }
        else if(ComparaData(data1, data2) == -1){
            printf("A primeira data eh mais antiga\n");
        }
        else {
            printf("As datas sao iguais\n");
        }
        printf("A diferenca em dias entre as datas eh: %02d dias\n", CalculaDiferencaDias(data1, data2));
    }
    else {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }
        

    return 0;
}