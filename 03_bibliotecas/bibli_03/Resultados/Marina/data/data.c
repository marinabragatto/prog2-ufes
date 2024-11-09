#include <stdio.h>
#include "data.h"

int verificaDataValida(int dia, int mes, int ano){
    if(mes > 12 || mes < 1){
        return 0;
    }
    if(dia > numeroDiasMes(mes, ano)){
        return 0;
    }
    return 1;
}

void imprimeMesExtenso(int mes){
    if(mes == 1){
        printf("Janeiro");
    }
    if(mes == 2){
        printf("Fevereiro");
    }
    if(mes == 3){
        printf("Marco");
    }
    if(mes == 4){
        printf("Abril");
    }
    if(mes == 5){
        printf("Maio");
    }
    if(mes == 6){
        printf("Junho");
    }
    if(mes == 7){
        printf("Julho");
    }
    if(mes == 8){
        printf("Agosto");
    }
    if(mes == 9){
        printf("Setembro");
    }
    if(mes == 10){
        printf("Outubro");
    }
    if(mes == 11){
        printf("Novembro");
    }
    if(mes == 12){
        printf("Dezembro");
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
    return;
}

int verificaBissexto(int ano){
    if(ano % 4 == 0){
        if(ano % 100 == 0){
            if(ano % 400 == 0){
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }


    /*
    Se o ano for uniformemente divisível por 4, vá para a etapa 2. Caso contrário, vá para a etapa 5.
    Se o ano for uniformemente divisível por 100, vá para a etapa 3. Caso contrário, vá para a etapa 4.
    Se o ano for uniformemente divisível por 400, vá para a etapa 4. Caso contrário, vá para a etapa 5.
    O ano é bissexto (tem 366 dias).
    O ano não é um ano bissexto (tem 365 dias).
    
    */
}

int numeroDiasMes(int mes, int ano){
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        return 31;
    }
    else if(mes != 2){
        return 30;
    }
    else if(mes == 2){
        if(verificaBissexto(ano)){
            return 29;
        }
        else{
            return 28;
        }
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(ano1 > ano2){
        return 1;
    }
    else if(ano1 < ano2){
        return -1;
    }
    else if(ano1 == ano2){
        if(mes1 > mes2){
            return 1;
        }
        else if(mes1 < mes2){
            return -1;
        }
        else if(mes1 == mes2){
            if(dia1 > dia2){
                return 1;
            }
            else if(dia1 < dia2){
                return -1;
            }
            else if(dia1 == dia2){
                return 0;
            }
        }
    }
}

int calculaDiasAteMes(int mes, int ano){
    int i = 0, dias = 0;
    for(i = 1; i < mes; i++){
        dias += numeroDiasMes(i, ano);
    }
    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int distancia = 0;
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0){
        return distancia;
    }
    else if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1){
        int dia3 = dia2, mes3 = mes2, ano3 = ano2;
        while(1){    
            if(dia3 < numeroDiasMes(mes3, ano3)){
                dia3++;
                distancia++;
            }
            else if(mes3 != 12){
                mes3++;
                dia3 = 1;
                distancia++;
            }
            else if(mes3 == 12){
                ano3++;
                mes3 = 1;
                dia3 = 1;
                distancia++;
            }
            if(comparaData(dia1, mes1, ano1, dia3, mes3, ano3) == 0){
                break;
            }
        }
    } else if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1){
        int dia3 = dia1, mes3 = mes1, ano3 = ano1;
        while(1){    
            if(dia3 < numeroDiasMes(mes3, ano3)){
                dia3++;
                distancia++;
            }
            else if(mes3 != 12){
                mes3++;
                dia3 = 1;
                distancia++;
            }
            else if(mes3 == 12){
                ano3++;
                mes3 = 1;
                dia3 = 1;
                distancia++;
            }
            if(comparaData(dia2, mes2, ano2, dia3, mes3, ano3) == 0){
                break;
            }
        }
    }
    return distancia;
}