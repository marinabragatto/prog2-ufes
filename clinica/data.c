#include "utils.h"

void imprimeData(tData data){
    printf("%02d/%02d/%02d\n", data.dia, data.mes, data.ano);
    return;
}

tData leData(){
    tData data;
    scanf("%*[^0-9]");
    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
    return data;
}

int retornaIdade(tData data){
    return (((data.dia > 12 && data.mes == 9) || data.mes > 9) ? 2022 - data.ano : 2023 - data.ano);
}