#include "data.h"

int main(){
    tData *data1, *data2;
    data1 = CriaData();
    data2 = CriaData();

    LeData(data1);
    LeData(data2);
    if(!VerificaDataValida(data1) || !VerificaDataValida(data2)){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }
    else{
        printf("Primeira data: ");
        ImprimeDataExtenso(data1);
        printf("Segunda data: ");
        ImprimeDataExtenso(data2);
        if(ComparaData(data1, data2) == -1){
            printf("A primeira data eh mais antiga\n");
        }
        else if(ComparaData(data1, data2) ==  -1){

        }
        else if(ComparaData(data1,data2) == 0){
            printf("As datas sao iguais\n");
        }

        printf("A diferenca em dias entre as datas eh: %02d dias\n", CalculaDiferencaDias(data1, data2));

    //    Primeira data: 28 de Janeiro de 2002
//Segunda data: 20 de Fevereiro de 2002
//A primeira data eh mais antiga/
//

    }

    LiberaData(data2);
    LiberaData(data1);

    return 0;
}